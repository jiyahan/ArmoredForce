#include "CFileStream.h"
#include "../../utility/tool/CCriticalSectionScope.h"


atom::CFileStream::CFileStream() : 
nest(NULL),read(false),full(0),site(0),file(NULL)
{
}

atom::CFileStream::~CFileStream() 
{
}

#if defined(__linux) || defined(__APPLE__)
void atom::CFileStream::SetDevice(const char * filepath) 
{
    if( filepath ) {
        name = filepath;
    }
}
#endif

#if defined(_WIN32)
void atom::CFileStream::SetDevice(const wchar_t * filepath) 
{
    if( filepath ) {
        name = filepath;
    }
}
#endif

void atom::CFileStream::SetOffset(U64 offset)
{
    if( file )
    {
        /* seek file */
        #ifdef _WIN32
        _fseeki64( file, static_cast<long long>(offset), SEEK_SET );
        #endif

		/* use fseeko to replace fseek */
		/* in apple os X, off_t is int64 */
		/* in linux, off_t size depend on compiler macro */
        #if defined(__linux) || defined(__APPLE__)
        fseeko( file, offset, SEEK_SET );
        #endif
    }
}

#if defined(__linux) || defined(__APPLE__)
U64 atom::CFileStream::GetLength(const char * filepath)
{
    U64 result = 0;
    if( filepath )
    {
        /* linux file stat not tested */
        /* apple mac os x file stat.st_size is 64 bits wide */
        struct stat buffer;
        stat( filepath, & buffer );
        result = static_cast<U64>( buffer.st_size );
    }
    return result;
}
#endif

#if defined(_WIN32)
U64 atom::CFileStream::GetLength(const wchar_t * filepath)
{
    U64 result = 0;
    if( filepath )
    {
        struct __stat64 buffer; 
        _wstat64( filepath, & buffer );
        result = static_cast<U64>( buffer.st_size );
    }
    return result;
}
#endif

int atom::CFileStream::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int atom::CFileStream::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int atom::CFileStream::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

atom::IInterface * atom::CFileStream::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CFileStream::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

char atom::CFileStream::Read() 
{
    char result = 0;
    Read( &result, sizeof(char) );
    return result;
}

U64 atom::CFileStream::Read(void * data, U64 length) 
{
    U64 result = 0;
    if( data && length )
    {
        CCriticalSectionScope scope( section );
        if( file )
        {
            /* loop read while finished */
            for( ;; ) 
            {
                /* read data */
                result += fread( reinterpret_cast<char *>(data) + result, 
                    1, static_cast<size_t>(length - result), file );

                /* read complete */
                if( result >= length ) {
                    break;
                }
            
                /* is eof ? */ 
                if( feof(file) ) {
                    break;
                }

                /* is error occur ? */ 
                if( ferror(file) ) {
                    perror( "read failed!" );
                    break;
                }
            }

            /* record new site */ 
            site += result;
        }
    }
    return result;
}

U64 atom::CFileStream::Read(void * value, U64 offset, U64 length) 
{
    return Read( reinterpret_cast<char *>(value) + offset, length );
}

void atom::CFileStream::Write(char value) 
{
    Write( & value, sizeof(char) );
}

void atom::CFileStream::Write(const void * data, U64 length) 
{
    if( data && length )
    {
        CCriticalSectionScope scope( section );
        if( file && read == false )
        {
            /* loop read while finished */
            U64 value = 0;
            for( ;; ) 
            {
                /* write data */
                value += fwrite( reinterpret_cast<const char *>(data) + value, 
                    1, static_cast<size_t>(length - value), file );

                /* read complete */
                if( value >= length ) {
                    break;
                }
            
                /* is error occur ? */ 
                if( ferror(file) ) {
                    perror( "write failed!" );
                    break;
                }
            }

            /* record new file length */
            site += value; full = atom_max( site, full );
        }
    }
}

void atom::CFileStream::Write(const void * value, U64 offset, U64 length) 
{
    Write( reinterpret_cast<const char *>(value) + offset, length );
}

void atom::CFileStream::Close() 
{
    CCriticalSectionScope scope( section );
    if( file ) fclose( file );
	file = NULL;
    site = 0;
    full = 0;
}

void atom::CFileStream::Truncate() 
{
    CCriticalSectionScope scope( section );
    if( !name.empty() && !read )
    {
        /* close file first, and then reopen file and truncate it. */
        if( file ) fclose( file );
        
        #if defined(__linux) || defined(__APPLE__)
        file = fopen( name.c_str(), "wb+" );
        #endif

        #if defined(_WIN32)
        file = _wfopen( name.c_str(), L"wb+" );
        #endif

        site = 0;
        full = GetLength( name.c_str() );
    }
}

void atom::CFileStream::Flush() 
{
    CCriticalSectionScope scope( section );
    if( file && !read ) {
        fflush( file );
    }
}

U64 atom::CFileStream::Available() 
{
    U64 result = 0;
    CCriticalSectionScope scope( section );
    if( site < full ) result = full - site;
    return result;
}

U64 atom::CFileStream::Length() 
{
    CCriticalSectionScope scope( section );
    return full;
}

void atom::CFileStream::Mark(U64 offset) 
{
    CCriticalSectionScope scope( section );
    if( file )
    {
        site = atom_min( offset, full );
        SetOffset( site );
    }
}

void atom::CFileStream::Reset() 
{
    CCriticalSectionScope scope( section );
    if( file )
    {
        full = GetLength( name.c_str() );
        site = 0;
        SetOffset( 0 );
    }
}

I64 atom::CFileStream::Skip(I64 bytes) 
{
    I64 okey = 0;
    CCriticalSectionScope scope( section );
    if( file )
    {
        I64 offset = static_cast<I64>( site ) + bytes;

        offset = atom_max( offset, 0 );
        offset = atom_min( offset, static_cast<I64>(full) );

        okey = offset - static_cast<I64>( site );
        site = static_cast<U64>( offset ); 
        SetOffset( site );
    }
    return okey;
}

bool atom::CFileStream::Assign(CMemory & data) 
{
    /* not support */
    UNREFERENCED_PARAMETER( data );
    return false;
}

bool atom::CFileStream::Swap(CMemory & data) 
{
    /* not support */
    UNREFERENCED_PARAMETER( data );
    return false;
}

bool atom::CFileStream::Clone(CMemory & data) 
{
    bool result = false;
    CCriticalSectionScope scope( section );
    if( file )
    {
        /* read file into memory */
        U64 length;
        length = GetLength( name.c_str() );
        length = atom_max( full, length );

        if( data.Alloc( static_cast<size_t>(length + 1) ) )
        {
            /* clear memory */
            U64 value = 0;
            memset( data, 0, data.GetCapacity() );

            /* seek to file begin */
            SetOffset( 0 );

            /* loop read while finished */
            for( ;; ) 
            {
                /* read data */
                value += fread( data.Query<char>() + value, 1, (size_t)(length - value), file );

                /* read complete */
                if( value >= length ) {
                    result = true;  break;
                }
            
                /* is eof ? */ 
                if( feof(file) ) {
                    result = false; break;
                }

                /* is error occur ? */ 
                if( ferror(file) ) {
                    perror( "read failed! " );
                    result = false; break;
                }
            }

            /* if succeed, set data length */
            if( result ) {
                data.SetLength( static_cast<size_t>(length) );
            }

            /* seek to current offset */
            SetOffset( site );
        }
    }
    return result;
}

bool atom::CFileStream::Open() 
{
    bool okey = false;
    CCriticalSectionScope scope( section );
    if( !name.empty() )
    {
        // 如果存在，则打开；
        #if defined(__linux) || defined(__APPLE__)
        file = fopen( name.c_str(), "rb+" );
        #endif

        #if defined(_WIN32)
        file = _wfopen( name.c_str(), L"rb+" );
        #endif

        if( file ) 
        {
            site = 0;
            full = GetLength( name.c_str() ); 
            okey = true;
        }

        // 如果不存在，则创建；
        else
        {
            #if defined(__linux) || defined(__APPLE__)
            file = fopen( name.c_str(), "wb+" );
            #endif

            #if defined(_WIN32)
            file = _wfopen( name.c_str(), L"wb+" );
            #endif

            if( file )
            {
                site = 0;
                full = GetLength( name.c_str() ); 
                okey = true;
            }
            else
            {
                #if defined(__linux) || defined(__APPLE__)
                file = fopen( name.c_str(), "rb" );
                #endif

                #if defined(_WIN32)
                file = _wfopen( name.c_str(), L"rb" );
                #endif

                if( file )
                {
                    read = true;
                    site = 0;
                    full = GetLength( name.c_str() ); 
                    okey = true;
                }
            }
        }
    }
    return okey;
}

bool atom::CFileStream::IsReadOnly() 
{
    CCriticalSectionScope scope( section );
    return read;
}
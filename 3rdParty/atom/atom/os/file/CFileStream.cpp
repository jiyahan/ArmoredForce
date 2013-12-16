#include "CFileStream.h"
#include "../../utility/tool/CCriticalSectionScope.h"
//Begin section for file CFileStream.cpp
//TODO: Add definitions that you want preserved
//End section for file CFileStream.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFileStream::CFileStream() : 
nest(NULL),read(false),full(0),site(0),file(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CFileStream::~CFileStream() 
{
    //TODO Auto-generated method stub
}

#if defined(__linux) || defined(__APPLE__)
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::SetDevice(const char * filepath) 
{
    //TODO Auto-generated method stub
    if( filepath ) {
        name = filepath;
    }
}
#endif

#if defined(_WIN32)
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::SetDevice(const wchar_t * filepath) 
{
    //TODO Auto-generated method stub
    if( filepath ) {
        name = filepath;
    }
}
#endif

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::SetOffset(U64 offset)
{
    //TODO Auto-generated method stub
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
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::GetLength(const char * filepath)
{
    //TODO Auto-generated method stub
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
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::GetLength(const wchar_t * filepath)
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CFileStream::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CFileStream::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CFileStream::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CFileStream::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
char atom::CFileStream::Read() 
{
    //TODO Auto-generated method stub
    char result = 0;
    Read( &result, sizeof(char) );
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::Read(void * data, U64 length) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::Read(void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    return Read( reinterpret_cast<char *>(value) + offset, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Write(char value) 
{
    //TODO Auto-generated method stub
    Write( & value, sizeof(char) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Write(const void * data, U64 length) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Write(const void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    Write( reinterpret_cast<const char *>(value) + offset, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Close() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    if( file ) fclose( file );
	file = NULL;
    site = 0;
    full = 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Truncate() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Flush() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    if( file && !read ) {
        fflush( file );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::Available() 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    CCriticalSectionScope scope( section );
    if( site < full ) result = full - site;
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CFileStream::Length() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    return full;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Mark(U64 offset) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    if( file )
    {
        site = atom_min( offset, full );
        SetOffset( site );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CFileStream::Reset() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    if( file )
    {
        full = GetLength( name.c_str() );
        site = 0;
        SetOffset( 0 );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 atom::CFileStream::Skip(I64 bytes) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFileStream::Assign(CMemory & data) 
{
    //TODO Auto-generated method stub
    /* not support */
    UNREFERENCED_PARAMETER( data );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFileStream::Swap(CMemory & data) 
{
    //TODO Auto-generated method stub64 
    /* not support */
    UNREFERENCED_PARAMETER( data );
    return false;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFileStream::Clone(CMemory & data) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFileStream::Open() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CFileStream::IsReadOnly() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    return read;
}
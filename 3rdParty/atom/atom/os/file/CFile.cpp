#include "CFile.h"
#include "../character/CCharacter.h"
#include "../../utility/charset/CUtf8Charset.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CFile::CFile(const char * name) 
{
    stream.SetNest( this );
    if( name ) 
	{
		#if defined(__APPLE__)
		if( CUtf8Charset::IsUtf8(name) ) {
			stream.SetDevice( name );
		} else {
			stream.SetDevice( CCharacter::MultiBytesToUtf8(name).c_str() );
		}
        #endif

        #if defined(_WIN32)
        if( CUtf8Charset::IsUtf8(name) ) {
            stream.SetDevice( CCharacter::Utf8ToUnicode      (name).c_str() );
        } else {
            stream.SetDevice( CCharacter::MultiBytesToUnicode(name).c_str() );
        }
        #endif

        #if defined(__linux)
        stream.SetDevice( name );
		#endif
    }
}

atom::CFile::CFile(const wchar_t * name) 
{
    stream.SetNest( this );
    if( name ) 
	{
		#if defined(__APPLE__) || defined(__linux)
        stream.SetDevice( CCharacter::UnicodeToUtf8( name ).c_str() );
        #endif

        #if defined(_WIN32)
        stream.SetDevice( name );
		#endif
    }
}

atom::CFile::~CFile() 
{
    stream.Close();
}

atom::IInterface * atom::CFile::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_STREAM:
    case IID_FILE_STREAM:
        result = & stream;
        break;
    }
    return result;
}

bool atom::CFile::Open() 
{
    return stream.Open();
}

void atom::CFile::Mark(U64 position) 
{
    stream.Mark( position );
}

void atom::CFile::Close() 
{
    stream.Close();
}

U64 atom::CFile::Length() 
{
    return stream.Length();
}

bool atom::CFile::IsReadOnly()
{
    return stream.IsReadOnly();
}

bool atom::CFile::Erase(const char * file) 
{
    bool result = false;
    if( file ) 
	{
		#if defined(__APPLE__)
		if( CUtf8Charset::IsUtf8(file) ) {
            result = ( 0 == remove( file ) );
		} else {
            result = ( 0 == remove( CCharacter::MultiBytesToUtf8(file).c_str() ) );
		}
        #endif

        #if defined(_WIN32)
		if( CUtf8Charset::IsUtf8(file) ) {
            result = ( 0 == _wremove( CCharacter::Utf8ToUnicode      (file).c_str() ) );
		} else {
            result = ( 0 == _wremove( CCharacter::MultiBytesToUnicode(file).c_str() ) );
		}
        #endif

        #if defined(__linux)
        result = ( 0 == remove( file ) );
		#endif
    }
    return result;
}

bool atom::CFile::Erase(const wchar_t * file) 
{
    bool result = false;
    if( file ) 
	{
		#if defined(__APPLE__) || defined(__linux)
        result = ( 0 == remove( CCharacter::UnicodeToUtf8(file).c_str() ) );
        #endif

        #if defined(_WIN32)
        result = ( 0 == _wremove(file) );
		#endif
	}
    return result;
}

atom::CMemory atom::CFile::LoadFile(const char * name) 
{
    CMemory result;

    CFile file( name );
    if( file.Open() )
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) {
            segment -> Clone( result );
        }
    }
    return result;
}

atom::CMemory atom::CFile::LoadFile(const wchar_t * name) 
{
    CMemory result;

    CFile file( name );
    if( file.Open() )
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) {
            segment -> Clone( result );
        }
    }
    return result;
}

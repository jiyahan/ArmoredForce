#include "CWin32Library.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"


atom::CWin32Library::CWin32Library() : 
handle(NULL)
{
}

atom::CWin32Library::~CWin32Library() 
{
    #ifdef _WIN32
    if( handle ) Close();
    #endif
}

bool atom::CWin32Library::Open(const char * value) 
{
    bool result = false;
    if( value )
    {
        #ifdef _WIN32
        if( handle == NULL )
        {
			a_wstring file;
			if( CUtf8Charset::IsUtf8(value) ) {
                file = CCharacter::Utf8ToUnicode      ( value );
			} else {
                file = CCharacter::MultiBytesToUnicode( value );
			}

            CPath path( file.c_str() );
            if( path.IsMatch("*.dll") )
            {
                result = ( ( handle = LoadLibraryW( file.c_str() ) ) != NULL );
                locate = file;
            }
        }
        #endif
    }
    return result;
}

bool atom::CWin32Library::Open(const wchar_t * file) 
{
    bool result = false;
    if( file )
    {
        #ifdef _WIN32
        if( handle == NULL )
        {
            CPath path( file );
            if( path.IsMatch("*.dll") )
            {
                result = ( ( handle = LoadLibraryW(file) ) != NULL );
                locate = file;
            }
        }
        #endif
    }
    return result;
}

void * atom::CWin32Library::GetFunction(const char * name) 
{
    void * result = NULL;
    if( name )
    {
        #ifdef _WIN32
        if( handle )
        {
            result = (LPVOID) GetProcAddress( (HINSTANCE)handle, name );
        }
        #endif
    }
    return result;
}
bool atom::CWin32Library::Close() 
{
    bool result = false;
    #ifdef _WIN32
    if( handle ) 
    {
        if( FreeLibrary( (HINSTANCE)handle ) == TRUE ) {
            locate.clear();
            handle = NULL; result = true;
        }
    }
    #endif
    return result;
}
atom::a_string atom::CWin32Library::GetPath() 
{
    return CCharacter::UnicodeToUtf8( locate.c_str() );
}

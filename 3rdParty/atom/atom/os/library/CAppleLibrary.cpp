#include "CAppleLibrary.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"


atom::CAppleLibrary::CAppleLibrary() : 
handle(NULL)
{
}

atom::CAppleLibrary::~CAppleLibrary() 
{
    #ifdef __APPLE__
    if( handle ) Close();
    #endif
}

bool atom::CAppleLibrary::Open(const char * value) 
{
    bool result = false;
    if( value )
    {
        #ifdef __APPLE__
        if( handle == NULL )
        {
			a_string file;
			if( CUtf8Charset::IsUtf8(value) ) {
				file = value;
			} else {
				file = CCharacter::MultiBytesToUtf8( value );
			}

			CPath path( file.c_str() );
            if( path.IsMatch("*.so") )
            {
                locate = file;
                handle = dlopen( file.c_str(), RTLD_LAZY );
                result = handle != NULL;

                if( !result ) {
                    printf( "ERROR: %s\n", dlerror() );
                }
            }
        }
        #endif
    }
    return result;
}

bool atom::CAppleLibrary::Open(const wchar_t * file) 
{
    if( !file ) return false;
	return Open( CCharacter::UnicodeToUtf8(file).c_str() );
}

void * atom::CAppleLibrary::GetFunction(const char * name) 
{
    void * result = NULL;
    if( name )
    {
        #ifdef __APPLE__
        if( handle )
        {
            if( ( result = dlsym(handle, name) ) == NULL ) {
                printf( "ERROR: %s\n", dlerror() );
            }
        }    
        #endif
    }
    return result;
}

bool atom::CAppleLibrary::Close() 
{
    bool result = false;
    #ifdef __APPLE__
    if( handle )
    {
        result = ( dlclose(handle) == 0 );
        if( result )
        {
            handle = NULL; locate.clear();
        }
        else 
        {
            printf( "ERROR: %s\n", dlerror() );
        }
    }
    #endif
    return result;
}

atom::a_string atom::CAppleLibrary::GetPath() 
{
    return locate;
}

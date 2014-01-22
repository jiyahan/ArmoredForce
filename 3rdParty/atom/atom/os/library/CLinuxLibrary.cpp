#include "CLinuxLibrary.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"


atom::CLinuxLibrary::CLinuxLibrary() : 
handle(NULL)
{
}

atom::CLinuxLibrary::~CLinuxLibrary() 
{
    #ifdef __linux
    if( handle ) Close();
    #endif
}

bool atom::CLinuxLibrary::Open(const char * file) 
{
    bool result = false;
    if( file )
    {
        #ifdef __linux
        if( handle == NULL )
        {
            CPath path( file );
            if( path.IsMatch("*.so") )
            {
                locate = file;
                handle = dlopen( file, RTLD_LAZY );
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

bool atom::CLinuxLibrary::Open(const wchar_t * file) 
{
    if( !file ) return false;
    return Open( CCharacter::UnicodeToUtf8(file).c_str() );
}

void * atom::CLinuxLibrary::GetFunction(const char * name) 
{
    void * result = NULL;
    if( name )
    {
        #ifdef __linux
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

bool atom::CLinuxLibrary::Close() 
{
    bool result = false;
    #ifdef __linux
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

atom::a_string atom::CLinuxLibrary::GetPath() 
{
    if( CUtf8Charset::IsUtf8( locate.c_str() ) ) {
        return locate;
    }
    
    return CCharacter::MultiBytesToUtf8( locate.c_str() );
}

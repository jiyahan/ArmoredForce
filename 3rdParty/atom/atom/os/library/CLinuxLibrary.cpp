#include "CLinuxLibrary.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"
//Begin section for file CLinuxLibrary.cpp
//TODO: Add definitions that you want preserved
//End section for file CLinuxLibrary.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLinuxLibrary::CLinuxLibrary() : 
handle(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLinuxLibrary::~CLinuxLibrary() 
{
    //TODO Auto-generated method stub
    #ifdef __linux
    if( handle ) Close();
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLinuxLibrary::Open(const char * file) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLinuxLibrary::Open(const wchar_t * file) 
{
    //TODO Auto-generated method stub
    if( !file ) return false;
    return Open( CCharacter::UnicodeToUtf8(file).c_str() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void * atom::CLinuxLibrary::GetFunction(const char * name) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CLinuxLibrary::Close() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CLinuxLibrary::GetPath() 
{
    //TODO Auto-generated method stub
    if( CUtf8Charset::IsUtf8( locate.c_str() ) ) {
        return locate;
    }
    
    return CCharacter::MultiBytesToUtf8( locate.c_str() );
}

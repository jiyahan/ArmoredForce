#include "CAppleLibrary.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"
//Begin section for file CAppleLibrary.cpp
//TODO: Add definitions that you want preserved
//End section for file CAppleLibrary.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleLibrary::CAppleLibrary() : 
handle(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleLibrary::~CAppleLibrary() 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    if( handle ) Close();
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleLibrary::Open(const char * value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleLibrary::Open(const wchar_t * file) 
{
    //TODO Auto-generated method stub
    if( !file ) return false;
	return Open( CCharacter::UnicodeToUtf8(file).c_str() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void * atom::CAppleLibrary::GetFunction(const char * name) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleLibrary::Close() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CAppleLibrary::GetPath() 
{
    //TODO Auto-generated method stub
    return locate;
}

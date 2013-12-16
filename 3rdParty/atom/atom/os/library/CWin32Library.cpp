#include "CWin32Library.h"
#include "../character/CCharacter.h"
#include "../path/CPath.h"
#include "../../utility/charset/CUtf8Charset.h"
//Begin section for file CWin32Library.cpp
//TODO: Add definitions that you want preserved
//End section for file CWin32Library.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Library::CWin32Library() : 
handle(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Library::~CWin32Library() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( handle ) Close();
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Library::Open(const char * value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Library::Open(const wchar_t * file) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void * atom::CWin32Library::GetFunction(const char * name) 
{
    //TODO Auto-generated method stub
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
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Library::Close() 
{
    //TODO Auto-generated method stub
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
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CWin32Library::GetPath() 
{
    //TODO Auto-generated method stub
    return CCharacter::UnicodeToUtf8( locate.c_str() );
}

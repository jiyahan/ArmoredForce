#include "CWin32Signal.h"
//Begin section for file CWin32Signal.cpp
//TODO: Add definitions that you want preserved
//End section for file CWin32Signal.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Signal::CWin32Signal() : handle(NULL)
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    handle = CreateEvent( NULL, TRUE, TRUE, NULL );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Signal::CWin32Signal(const char * name) : handle(NULL)
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    handle = CreateEvent( NULL, TRUE, TRUE, name );
    #else
    UNREFERENCED_PARAMETER( name );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CWin32Signal::~CWin32Signal() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    if( handle ) CloseHandle( handle );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Signal::Reset() 
{
    //TODO Auto-generated method stub
    bool result = false;
    #ifdef _WIN32
    if( handle ) {
        result = ( ResetEvent(handle) == TRUE );
    }
    #endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Signal::Awake() 
{
    //TODO Auto-generated method stub
    bool result = false;
    #ifdef _WIN32
    if( handle ) {
        result = ( SetEvent(handle) == TRUE );
    }
    #endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CWin32Signal::Await(U64 timeout) 
{
    //TODO Auto-generated method stub
    bool result = false;
    
    #ifdef _WIN32
    if( handle ) {
        WaitForSingleObject( handle, static_cast<DWORD>(timeout) );
        result = true;
    }

    #else

    UNREFERENCED_PARAMETER( timeout );
    #endif

    return result;
}

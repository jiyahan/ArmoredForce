#include "CWin32Signal.h"


atom::CWin32Signal::CWin32Signal() : handle(NULL)
{
    #ifdef _WIN32
    handle = CreateEvent( NULL, TRUE, TRUE, NULL );
    #endif
}

atom::CWin32Signal::CWin32Signal(const char * name) : handle(NULL)
{
    #ifdef _WIN32
    handle = CreateEvent( NULL, TRUE, TRUE, name );
    #else
    UNREFERENCED_PARAMETER( name );
    #endif
}

atom::CWin32Signal::~CWin32Signal() 
{
    #ifdef _WIN32
    if( handle ) CloseHandle( handle );
    #endif
}

bool atom::CWin32Signal::Reset() 
{
    bool result = false;
    #ifdef _WIN32
    if( handle ) {
        result = ( ResetEvent(handle) == TRUE );
    }
    #endif
    return result;
}

bool atom::CWin32Signal::Awake() 
{
    bool result = false;
    #ifdef _WIN32
    if( handle ) {
        result = ( SetEvent(handle) == TRUE );
    }
    #endif
    return result;
}

bool atom::CWin32Signal::Await(U64 timeout) 
{
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

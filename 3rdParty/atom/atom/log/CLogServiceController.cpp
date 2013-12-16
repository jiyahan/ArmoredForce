#include "CLogServiceController.h"
#include "../utility/tool/CCriticalSectionScope.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../os/timer/CSystemTimer.h"
#include "../enumeration/LOG_LEVEL.h"
//Begin section for file CLogServiceController.cpp
//TODO: Add definitions that you want preserved
//End section for file CLogServiceController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogServiceController::CLogServiceController() : 
nest(NULL),time(0),show(LL_DEBUG)
{
    //TODO Auto-generated method stub
    time = CMilisecondTimer::Now();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLogServiceController::~CLogServiceController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CLogServiceController::IncRef() 
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
int atom::CLogServiceController::DecRef() 
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
int atom::CLogServiceController::GetRef() 
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
atom::IInterface * atom::CLogServiceController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceController::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceController::Setup(U08 display_level, IInterface * output) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    show = display_level;
    data.Attach( output );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceController::Clear() 
{
    //TODO Auto-generated method stub
    lock.Enter();
    logs.clear();
    lock.Leave();

    clog.Enter();
    data.Detach();
    clog.Leave();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceController::Write(U08 level, const char * log) 
{
    //TODO Auto-generated method stub
    if( log )
    {
        a_string value;
        CSystemTimer::TimeToString( CSystemTimer::Now(), value );

        char msg[128];
        sprintf( msg, " [%010.3fs]", ( CMilisecondTimer::Now() - time ) * 0.001f );
        value += msg;

        switch( level )
        {
        case LL_DEBUG:
            value += "[DEBUG] ";
            break;
        case LL_ALARM:
            value += "[ALARM] ";
            break;
        case LL_ERROR:
            value += "[ERROR] ";
            break;
        default:
            value += "[UNDEF] ";
            break;
        }

        value += log;
        value += "\r\n";

        lock.Enter();
        logs.push_back( value );
        lock.Leave();

        if( level >= show )
        {
            #if defined(_WIN32)
            OutputDebugString( value.c_str() );
            #endif

            #if defined(__APPLE__) || defined(__linux)
            printf( "%s", value.c_str() );
            #endif
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLogServiceController::Flush() 
{
    //TODO Auto-generated method stub
    CLogServiceControllerBind swap;

    lock.Enter();
    swap.swap( logs );
    clog.Enter();
    lock.Leave();

    for( CLogServiceControllerBind::
        iterator it = swap.begin(); it != swap.end(); ++ it ) {
        data.Write( it -> c_str(), it -> length() );
    }

    data.Flush();
    clog.Leave();
}

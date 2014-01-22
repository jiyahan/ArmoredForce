#include "CLogServiceController.h"
#include "../utility/tool/CCriticalSectionScope.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../os/timer/CSystemTimer.h"
#include "../enumeration/LOG_LEVEL.h"


atom::CLogServiceController::CLogServiceController() : 
nest(NULL),time(0),show(LL_DEBUG)
{
    time = CMilisecondTimer::Now();
}

atom::CLogServiceController::~CLogServiceController() 
{
}

int atom::CLogServiceController::IncRef() 
{
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

int atom::CLogServiceController::DecRef() 
{
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

int atom::CLogServiceController::GetRef() 
{
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

atom::IInterface * atom::CLogServiceController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CLogServiceController::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CLogServiceController::Setup(U08 display_level, IInterface * output) 
{
    CCriticalSectionScope scope( clog );
    show = display_level;
    data.Attach( output );
}

void atom::CLogServiceController::Clear() 
{
    lock.Enter();
    logs.clear();
    lock.Leave();

    clog.Enter();
    data.Detach();
    clog.Leave();
}

void atom::CLogServiceController::Write(U08 level, const char * log) 
{
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

void atom::CLogServiceController::Flush() 
{
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

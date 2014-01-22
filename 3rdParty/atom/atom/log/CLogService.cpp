#include "CLogService.h"
#include "../maintainer/CMaintainer.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CLogService::CLogService()
{
    controller.SetNest( this );
	maintainer.SetNest( this );
	life      .SetNest( this );
}

atom::CLogService::~CLogService() 
{
}

void atom::CLogService::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CLogService::GetName() 
{
    return OID_LOG_SERVICE;
}

void atom::CLogService::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CLogService::GetType() 
{
    return OID_LOG_SERVICE;
}

const char * atom::CLogService::ToString() 
{
	static char name[] = "Log Service";
    return name;
}

int atom::CLogService::IncRef() 
{
	return lock.Increase();
}

int atom::CLogService::DecRef() 
{
    return lock.Decrease();
}

int atom::CLogService::GetRef() 
{
    return lock.GetReference();
}

atom::IInterface * atom::CLogService::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_LOG_SERVICE_CONTROLLER:
		if( controller.IncRef() )
			result = & controller;
        break;
	case IID_MAINTAINABLE:
		if( maintainer.IncRef() )
			result = & maintainer;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
        break;
    }
    return result;
}

bool atom::CLogService::Initiate() 
{
    return life.Initiate();
}

bool atom::CLogService::Shutdown() 
{
    return life.Shutdown();
}

void atom::CLogService::Attach(U08 display_level, IInterface * output) 
{
    controller.Setup( display_level, output );
}

void atom::CLogService::Record(U08 level, const char * log) 
{
    controller.Write( level, log );
}

#include "CEventService.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"


atom::CEventService::CEventService() 
{
	thread   .SetNest( this );
	container.SetNest( this );
	timeline .SetNest( this );
	entry    .SetNest( this );
	life     .SetNest( this );
	listener .SetNest( this );
}

atom::CEventService::~CEventService() 
{
}

void atom::CEventService::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CEventService::GetName() 
{
	return OID_EVENT_SERVICE;
}

void atom::CEventService::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CEventService::GetType() 
{
	return OID_EVENT_SERVICE;
}

const char * atom::CEventService::ToString() 
{
	static char name[] = "Event Service";
    return name;
}

int atom::CEventService::IncRef() 
{
	return counter.Increase();
}

int atom::CEventService::DecRef() 
{
	return counter.Decrease();
}

int atom::CEventService::GetRef() 
{
	return counter.GetReference();
}

atom::IInterface * atom::CEventService::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_INSTANCE_CONTAINER:
		if( container.IncRef() )
			result = & container;
        break;
    case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener .IncRef() )
			result = & listener;
        break;
	case IID_EVENT_SERVICE_TIMELINE:
		if( timeline .IncRef() )
			result = & timeline;
        break;
	case IID_INSTANCE_LIFE:
		if( life     .IncRef() )
			result = & life;
		break;
	case IID_THREAD_CONTROL:
		if( thread   .IncRef() )
			result = & thread;
		break;
	case IID_EVENT_SERVICE_ENTRY:
		if( entry    .IncRef() )
			result = & entry;
		break;
    }
    return result;
}

U64 atom::CEventService::Create() 
{
	return entry.Create();
}

void atom::CEventService::Remove(U64 name) 
{
	entry.Remove( name );
}

void atom::CEventService::Notify(U64 name) 
{
	timeline.Mark( CMilisecondTimer::Now(), name );
}

bool atom::CEventService::Initiate() 
{
	return life.Initiate();
}

bool atom::CEventService::Shutdown() 
{
	return life.Shutdown();
}

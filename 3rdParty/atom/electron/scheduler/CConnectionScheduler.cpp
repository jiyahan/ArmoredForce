#include "CConnectionScheduler.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"


electron::CConnectionScheduler::CConnectionScheduler() 
{
    emitter   .SetNest( this );
    listener  .SetNest( this );
    container .SetNest( this );
    life      .SetNest( this );
    receiver  .SetNest( this );
    threads   .SetNest( this );
    controller.SetNest( this );
    alias     .SetNest( this );
}

electron::CConnectionScheduler::~CConnectionScheduler() 
{
}

bool electron::CConnectionScheduler::Initiate(U32 thread_amount) 
{
    threads.SetThreadAmount( thread_amount );
    return life.Initiate();
}

bool electron::CConnectionScheduler::Shutdown() 
{
    return life.Shutdown();
}

U64 electron::CConnectionScheduler::Listen(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    return controller.Listen( address, port, io_model, message_queue );
}

U64 electron::CConnectionScheduler::Connect(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    return controller.Connect( address, port, io_model, message_queue );
}

bool electron::CConnectionScheduler::Send(U64 connector, CMessage * message) 
{
    return controller.Send( connector, message );
}

bool electron::CConnectionScheduler::Close(U64 connection_name) 
{
    return controller.Close( connection_name );
}

U64 electron::CConnectionScheduler::GetEventSpace() 
{
    return controller.GetSpace();
}

bool electron::CConnectionScheduler::GetStatistias(U64 connector, tagFlowStatistics & origin, tagFlowStatistics & actual, U64 & largest)
{
    bool result = false;
    CObjectPtr object = alias.Obtain( connector );
    if( object )
    {
        result = true;
        CInterface<IConnectorStubStatistics> segment;
        if( segment.Mount(object, IID_CONNECTOR_STUB_STATISTICS) ) {
            segment -> GetStatistics( largest, origin, actual ); 
        }
    }
    return result;
}

void electron::CConnectionScheduler::SetName(U64 name) 
{
    UNREFERENCED_PARAMETER( name );
}

U64 electron::CConnectionScheduler::GetName() 
{
    return OID_CONNECTION_SCHEDULER;
}

void electron::CConnectionScheduler::SetType(U32 type) 
{
    UNREFERENCED_PARAMETER( type );
}

U32 electron::CConnectionScheduler::GetType() 
{
    return OID_CONNECTION_SCHEDULER;
}

const char * electron::CConnectionScheduler::ToString() 
{
    static char name[] = "Connection Scheduler";
    return name;
}

int electron::CConnectionScheduler::IncRef() 
{
	return counter.Increase();
}

int electron::CConnectionScheduler::DecRef() 
{
    return counter.Decrease();
}

int electron::CConnectionScheduler::GetRef() 
{
    return counter.GetReference();
}

IInterface * electron::CConnectionScheduler::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_THREAD_CONTROL:
    case IID_MULTI_THREAD_CONTROL:
        if( threads   .IncRef() )
			result = & threads;
        break;
    case IID_INSTANCE_CONTAINER:
		if( container .IncRef() )
			result = & container;
        break;
    case IID_INSTANCE_ALIAS_CONTAINER:
        if( alias     .IncRef() )
			result = & alias;
        break;
    case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener  .IncRef() )
			result = & listener;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
		break;
    case IID_EVENT_EMITTER:
        if( emitter   .IncRef() )
			result = & emitter;
		break;
    case IID_EVENT_RECEIVER:
        if( receiver  .IncRef() )
			result = & receiver;
		break;
    case IID_CONNECTION_SCHEDULER_CONTROLLER:
        if( controller.IncRef() )
			result = & controller;
        break;
    }
    return result;
}

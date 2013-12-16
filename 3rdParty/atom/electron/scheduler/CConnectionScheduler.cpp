#include "CConnectionScheduler.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"
//Begin section for file CConnectionScheduler.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionScheduler.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionScheduler::CConnectionScheduler() 
{
    //TODO Auto-generated method stub
    emitter   .SetNest( this );
    listener  .SetNest( this );
    container .SetNest( this );
    life      .SetNest( this );
    receiver  .SetNest( this );
    threads   .SetNest( this );
    controller.SetNest( this );
    alias     .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionScheduler::~CConnectionScheduler() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionScheduler::Initiate(U32 thread_amount) 
{
    //TODO Auto-generated method stub
    threads.SetThreadAmount( thread_amount );
    return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionScheduler::Shutdown() 
{
    //TODO Auto-generated method stub
    return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionScheduler::Listen(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    //TODO Auto-generated method stub
    return controller.Listen( address, port, io_model, message_queue );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionScheduler::Connect(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    //TODO Auto-generated method stub
    return controller.Connect( address, port, io_model, message_queue );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionScheduler::Send(U64 connector, CMessage * message) 
{
    //TODO Auto-generated method stub
    return controller.Send( connector, message );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionScheduler::Close(U64 connection_name) 
{
    //TODO Auto-generated method stub
    return controller.Close( connection_name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionScheduler::GetEventSpace() 
{
    //TODO Auto-generated method stub
    return controller.GetSpace();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionScheduler::GetStatistias(U64 connector, tagFlowStatistics & origin, tagFlowStatistics & actual, U64 & largest)
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionScheduler::SetName(U64 name) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionScheduler::GetName() 
{
    //TODO Auto-generated method stub
    return OID_CONNECTION_SCHEDULER;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionScheduler::SetType(U32 type) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CConnectionScheduler::GetType() 
{
    //TODO Auto-generated method stub
    return OID_CONNECTION_SCHEDULER;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * electron::CConnectionScheduler::ToString() 
{
    //TODO Auto-generated method stub
    static char name[] = "Connection Scheduler";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionScheduler::IncRef() 
{
    //TODO Auto-generated method stub
	return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionScheduler::DecRef() 
{
    //TODO Auto-generated method stub
    return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionScheduler::GetRef() 
{
    //TODO Auto-generated method stub
    return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CConnectionScheduler::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

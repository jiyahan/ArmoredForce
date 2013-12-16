#include "CConnectionSchedulerEventReceiver.h"
#include "../interface/IConnectionSchedulerController.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CConnectionSchedulerEventReceiver.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerEventReceiver.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerEventReceiver::CConnectionSchedulerEventReceiver() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerEventReceiver::~CConnectionSchedulerEventReceiver() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerEventReceiver::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerEventReceiver::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerEventReceiver::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CConnectionSchedulerEventReceiver::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerEventReceiver::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerEventReceiver::OnEvent(const tagEvent & value) 
{
    //TODO Auto-generated method stub
    bool result = true;
	switch( value.handle )
	{
	case EID_CONNECTION_ESTABLISHED:
        {
			// submited by listener and inner space resubmit this by
			// event service thread
            CInterface<IConnectionSchedulerController> segment;
            if( segment.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
                result = segment -> OnConnectionOpen( value.source, value.append );
            }
        }
		break;
	case EID_CONNECTION_READY:
        // do nothing;
		break;
	case EID_CONNECTION_DISCONNECTED:
        {
			// submited by connector, io model thread
            CInterface<IConnectionSchedulerController> segment;
            if( segment.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
                segment -> OnConnectionLose( value.source );
            }
        }
		break;
	case EID_CONNECTION_CLOSED:
        // do nothing;
		break;
	case EID_CONNECTION_RECEIVE_DATA:
        {
			// submited by connector, io model thread
            CInterface<IConnectionSchedulerController> segment;
            if( segment.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
                segment -> OnReceive( value.source );
            }
        }
		break;
	}

    if( value.handle != EID_CONNECTION_RECEIVE_DATA )
	{
        CInterface<IEventEmitter> segment;
        if( segment.Mount(this, IID_EVENT_EMITTER) )
        {
            tagEvent eh;
            eh.handle = value.handle;
            eh.append = value.append;
            eh.record = value.record;
            eh.source = value.source;

            segment -> Report( eh );
        }
	}
    return result;
}

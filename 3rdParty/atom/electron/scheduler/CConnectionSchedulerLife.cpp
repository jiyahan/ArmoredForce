#include "CConnectionSchedulerLife.h"
#include "../interface/IConnectionSchedulerController.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectionSchedulerLife::CConnectionSchedulerLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

electron::CConnectionSchedulerLife::~CConnectionSchedulerLife() 
{
}

int electron::CConnectionSchedulerLife::IncRef() 
{
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

int electron::CConnectionSchedulerLife::DecRef() 
{
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

int electron::CConnectionSchedulerLife::GetRef() 
{
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

IInterface * electron::CConnectionSchedulerLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectionSchedulerLife::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CConnectionSchedulerLife::Initiate() 
{
    bool result = false;
    CInterface<IConnectionSchedulerController> segment_1;
    if( segment_1.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
        result = segment_1 -> Initiate();
    }

    CInterface<IThreadControl> segment_2;
    if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
        result = segment_2 -> OnBegin() && result;
    }
    return result;
}

bool electron::CConnectionSchedulerLife::Shutdown() 
{
    bool result = false;
    CInterface<IThreadControl> segment_1;
    if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
        result = segment_1 -> OnClose();
    }

    CInterface<IConnectionSchedulerController> segment_2;
    if( segment_2.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
        result = segment_2 -> Shutdown() && result;
    }

    CInterface<IEventEmitter> segment_3;
    if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
        segment_3 -> Detach();
    }

    CInterface<IInstanceAliasContainer<U64> > segment_4;
    if( segment_4.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
        segment_4 -> RemoveAll();
    }

    CInterface<IInstanceContainer> segment_5;
    if( segment_5.Mount(this, IID_INSTANCE_CONTAINER) ) {
        segment_5 -> RemoveAll();
    }
    return result;
}

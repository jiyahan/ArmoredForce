#include "CConnectorStubEventReceiver.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../enumeration/EVENT_ID.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectorStubEventReceiver::CConnectorStubEventReceiver() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

electron::CConnectorStubEventReceiver::~CConnectorStubEventReceiver() 
{
}

int electron::CConnectorStubEventReceiver::IncRef() 
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

int electron::CConnectorStubEventReceiver::DecRef() 
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

int electron::CConnectorStubEventReceiver::GetRef() 
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

IInterface * electron::CConnectorStubEventReceiver::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubEventReceiver::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CConnectorStubEventReceiver::OnEvent(const tagEvent & value) 
{
    bool result = false;
    CInterface<IEventEmitter> segment;
    if( segment.Mount(this ,IID_EVENT_EMITTER) ) {
        result = segment -> Report( value );
    }
    return result;
}

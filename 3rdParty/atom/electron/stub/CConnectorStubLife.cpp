#include "CConnectorStubLife.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../interface/IConnectorStubFrame.h"
#include "../interface/IConnectorStubHeartBeat.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectorStubLife::CConnectorStubLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

electron::CConnectorStubLife::~CConnectorStubLife() 
{
}

int electron::CConnectorStubLife::IncRef() 
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

int electron::CConnectorStubLife::DecRef() 
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

int electron::CConnectorStubLife::GetRef() 
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

IInterface * electron::CConnectorStubLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubLife::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CConnectorStubLife::Initiate() 
{
    if( nest )
    {
	    CObjectPtr object;
        object = CInstanceUtility::MakeObject( nest );
        if( object ) {
            CMaintainer::GetInstance() -> Attach( object );
        }
    }
    return true;
}

bool electron::CConnectorStubLife::Shutdown() 
{
    if( nest )
    {
        CMaintainer::GetInstance() -> Detach(
            CInstanceUtility::GetInstanceName(nest) );

        CInterface<IConnectorStubHeartBeat> segment_1;
        if( segment_1.Mount(this, IID_CONNECTOR_STUB_HEART_BEAT) ) {
            segment_1 -> Reset();
        }

        CInterface<IConnectorStubFrame> segment_2;
        if( segment_2.Mount(this, IID_CONNECTOR_STUB_FRAME) ) {
            segment_2 -> Shut();
        }

        CInterface<IEventEmitter> segment_3;
        if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
            segment_3 -> Detach();
        }

        CInterface<IConnectorStubStatistics> segment_4;
        if( segment_4.Mount(this, IID_CONNECTOR_STUB_STATISTICS) ) {
            segment_4 -> Reset();
        }
    }
    return true;
}

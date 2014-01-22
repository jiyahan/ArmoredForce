#include "CConnectorStubMaintainable.h"
#include "../interface/IConnectorStubHeartBeat.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectorStubMaintainable::CConnectorStubMaintainable() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

electron::CConnectorStubMaintainable::~CConnectorStubMaintainable() 
{
}

int electron::CConnectorStubMaintainable::IncRef() 
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

int electron::CConnectorStubMaintainable::DecRef() 
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

int electron::CConnectorStubMaintainable::GetRef() 
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

IInterface * electron::CConnectorStubMaintainable::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubMaintainable::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

U64 electron::CConnectorStubMaintainable::OnMaintenance(U64 now) 
{
    U64 result = U64(INFINITE);
    CInterface<IConnectorStubHeartBeat> segment;
    if( segment.Mount(this, IID_CONNECTOR_STUB_HEART_BEAT) ) {
        result = segment -> OnProcess( now );
    }
    return result;
}

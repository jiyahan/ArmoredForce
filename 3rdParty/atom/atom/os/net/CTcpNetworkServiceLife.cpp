#include "CTcpNetworkServiceLife.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/ITcpNetworkServiceController.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpNetworkServiceLife::CTcpNetworkServiceLife() : 
nest(NULL)
{
}

atom::CTcpNetworkServiceLife::~CTcpNetworkServiceLife() 
{
}

int atom::CTcpNetworkServiceLife::IncRef() 
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

int atom::CTcpNetworkServiceLife::DecRef() 
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

int atom::CTcpNetworkServiceLife::GetRef() 
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

atom::IInterface * atom::CTcpNetworkServiceLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpNetworkServiceLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpNetworkServiceLife::Initiate() 
{
	bool result = false;
	CInterface<ITcpNetworkServiceController> segment_1;
	if( segment_1.Mount(this, IID_TCP_NETWORK_SERVICE_CONTROLLER) ) {
		result = segment_1 -> Initiate();
	}
    return result;
}

bool atom::CTcpNetworkServiceLife::Shutdown() 
{
	bool result = false;

	CInterface<ITcpNetworkServiceController> segment_1;
	if( segment_1.Mount(this, IID_TCP_NETWORK_SERVICE_CONTROLLER) ) {
		result = segment_1 -> Shutdown();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_2 -> RemoveAll();
	}
    return result;
}

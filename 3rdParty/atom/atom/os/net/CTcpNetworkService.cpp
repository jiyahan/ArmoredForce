#include "CTcpNetworkService.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpNetworkService::CTcpNetworkService() : 
type(0),name(0)
{
	container .SetNest( this );
	listener  .SetNest( this );
	life      .SetNest( this );
	controller.SetNest( this );
}

atom::CTcpNetworkService::~CTcpNetworkService() 
{
}

void atom::CTcpNetworkService::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CTcpNetworkService::GetName() 
{
	return OID_TCP_NETWORK_SERVICE;
}

void atom::CTcpNetworkService::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CTcpNetworkService::GetType() 
{
	return OID_TCP_NETWORK_SERVICE;
}

const char * atom::CTcpNetworkService::ToString() 
{
	static char name[] = "Tcp Network Service";
    return name;
}

int atom::CTcpNetworkService::IncRef() 
{
	return lock.Increase();
}

int atom::CTcpNetworkService::DecRef() 
{
	return lock.Decrease();
}

int atom::CTcpNetworkService::GetRef() 
{
	return lock.GetReference();
}

atom::IInterface * atom::CTcpNetworkService::QueryInterface(U32 iid) 
{
	IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_CONTAINER:
		if( container .IncRef() )
			result = & container;
        break;
	case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener  .IncRef() )
			result = & listener;
        break;
	case IID_TCP_NETWORK_SERVICE_CONTROLLER:
		if( controller.IncRef() )
			result = & controller;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
		break;
    }
    return result;
}

bool atom::CTcpNetworkService::Initiate() 
{
	return life.Initiate();
}

bool atom::CTcpNetworkService::Shutdown() 
{
	return life.Shutdown();
}

atom::CObjectPtr atom::CTcpNetworkService::GetModel(U32 io_model) 
{
	return controller.GetModel( io_model );
}

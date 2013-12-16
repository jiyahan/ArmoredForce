#include "CTcpNetworkService.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpNetworkService.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpNetworkService.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkService::CTcpNetworkService() : 
type(0),name(0)
{
    //TODO Auto-generated method stub
	container .SetNest( this );
	listener  .SetNest( this );
	life      .SetNest( this );
	controller.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkService::~CTcpNetworkService() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpNetworkService::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CTcpNetworkService::GetName() 
{
    //TODO Auto-generated method stub
	return OID_TCP_NETWORK_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpNetworkService::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpNetworkService::GetType() 
{
    //TODO Auto-generated method stub
	return OID_TCP_NETWORK_SERVICE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CTcpNetworkService::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Tcp Network Service";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkService::IncRef() 
{
    //TODO Auto-generated method stub
	return lock.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkService::DecRef() 
{
    //TODO Auto-generated method stub
	return lock.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkService::GetRef() 
{
    //TODO Auto-generated method stub
	return lock.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpNetworkService::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkService::Initiate() 
{
    //TODO Auto-generated method stub
	return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkService::Shutdown() 
{
    //TODO Auto-generated method stub
	return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpNetworkService::GetModel(U32 io_model) 
{
    //TODO Auto-generated method stub
	return controller.GetModel( io_model );
}

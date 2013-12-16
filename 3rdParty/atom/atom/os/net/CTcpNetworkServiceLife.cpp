#include "CTcpNetworkServiceLife.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/ITcpNetworkServiceController.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpNetworkServiceLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpNetworkServiceLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkServiceLife::CTcpNetworkServiceLife() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpNetworkServiceLife::~CTcpNetworkServiceLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkServiceLife::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkServiceLife::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpNetworkServiceLife::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpNetworkServiceLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpNetworkServiceLife::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkServiceLife::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<ITcpNetworkServiceController> segment_1;
	if( segment_1.Mount(this, IID_TCP_NETWORK_SERVICE_CONTROLLER) ) {
		result = segment_1 -> Initiate();
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpNetworkServiceLife::Shutdown() 
{
    //TODO Auto-generated method stub
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

#include "CTcpConnectorEventEmitter.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IEventReceiver.h"
#include "../../interface/ITcpConnectionController.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpConnectorEventEmitter.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorEventEmitter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorEventEmitter::CTcpConnectorEventEmitter() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorEventEmitter::~CTcpConnectorEventEmitter() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpConnectorEventEmitter::IncRef() 
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
int atom::CTcpConnectorEventEmitter::DecRef() 
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
int atom::CTcpConnectorEventEmitter::GetRef() 
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
atom::IInterface * atom::CTcpConnectorEventEmitter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorEventEmitter::SetNest(IInterface * value) 
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
bool atom::CTcpConnectorEventEmitter::Attach(U64 object) 
{
    //TODO Auto-generated method stub
	CObjectPtr instance = CInstanceFactory::GetInstance() -> Inquire( object );
	return Attach( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorEventEmitter::Attach(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	CCriticalSectionScope scope( section );
	if( object && node == NULL ) {
		node = object; result = true;
	}
    return result;
}
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorEventEmitter::Detach() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( section );
    node = NULL;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorEventEmitter::Report(const tagEvent & value) 
{
    //TODO Auto-generated method stub
	bool result = false; 
	section.Enter();
	if( node )
	{
		CInterface<IEventReceiver> segment;
		if( segment.Mount(node, IID_EVENT_RECEIVER) ) {
			result = segment -> OnEvent( value );
		}
	}
	section.Leave();

	if( value.handle == EID_CONNECTION_DISCONNECTED )
	{
		// if connection disconnected by peer, try to close
		// the connection;
		CInterface<ITcpConnectionController> segment;
		if( segment.Mount(this, IID_TCP_CONNECTION_CONTROLLER) ) {
			segment -> Shut();
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorEventEmitter::Report(const char * target, const tagEvent & value) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( target )
	{
		tagEvent e( value ); e.target = target;
		result = Report( e );
	}
	return result;
}

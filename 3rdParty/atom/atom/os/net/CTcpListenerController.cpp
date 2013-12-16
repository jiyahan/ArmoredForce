#include "CTcpListenerController.h"
#include "CTcpNetworkService.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/ITcpIOModel.h"
#include "../../interface/ITcpConnectorController.h"
#include "../../interface/IEventEmitter.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CTcpListenerController.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpListenerController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpListenerController::CTcpListenerController() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
active(false),iomold(0),socket(INVALID_SOCKET)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpListenerController::~CTcpListenerController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpListenerController::IncRef() 
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
int atom::CTcpListenerController::DecRef() 
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
int atom::CTcpListenerController::GetRef() 
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
atom::IInterface * atom::CTcpListenerController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpListenerController::SetNest(IInterface * value) 
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
bool atom::CTcpListenerController::Open(const char * host, U16 port, U32 mold) 
{
    //TODO Auto-generated method stub
	// if argument is not valid, return false;
	if( !nest || !host || !port || !mold ) {
		return false;
	}

	// if io model is not valid, return false;
	CObjectPtr model = CTcpNetworkService::GetInstance() -> GetModel( mold );
	if( model == NULL ) {
		return false;
	}

	// enter cirtical seciton
	bool result = false;
	U64  object = CInstanceUtility::GetInstanceName( nest );
	CCriticalSectionScope scope( region );
	
	// get io model's interface;
	CInterface<ITcpIOModel> segment;
	if( segment.Mount(model, IID_TCP_IO_MODEL) )
	{
		socket = segment -> Create();
		if( INVALID_SOCKET != socket )
		{
			iomold = mold;
			domain.host = host;
			domain.port = port;

			// attach connector to io model, if succeed, try to 
			// receive peer message.
			if( segment -> Attach(object) &&
				segment -> Listen(object, domain) ) {
				active = true;
				result = segment -> Accept( object );
			}

			// if succeeded, update address.
			if( result ) {
				Update();
			}

			// if failed, detach connector from io model, and close
			// socket, clear class member arguments.
			else
			{
				segment -> Detach( object );
				segment -> Remove( socket );

				active = false;
				socket = INVALID_SOCKET;
				iomold = 0;

				domain.host.clear();
				domain.port = 0;
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpListenerController::Shut() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	if( active )
	{
		active = false;		
		CObjectPtr model =
			CTcpNetworkService::GetInstance() -> GetModel( iomold );
		if( model )
		{
			CInterface<ITcpIOModel> segment;
			if( segment.Mount(model, IID_TCP_IO_MODEL) )
			{
				segment -> Detach( CInstanceUtility::GetInstanceName(nest) );
				segment -> Remove( socket );

				domain.host.clear(); 
				domain.port = 0;

				socket = INVALID_SOCKET;
				iomold = 0;
			}
		}
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpListenerController::GetActive() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	return active;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
SOCKET atom::CTcpListenerController::GetSocket() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	return socket;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpListenerController::GetIOMold() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	return iomold;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CTcpListenerController::GetSelfAddress() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	return domain.host;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CTcpListenerController::GetSelfPort() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( region );
	return domain.port;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CTcpListenerController::Accept(SOCKET hs) 
{
    //TODO Auto-generated method stub
	if( hs == INVALID_SOCKET ) {
		return 0;
	}

	// if create instance failed, reutrn;
	CObjectPtr connector = 
		CInstanceUtility::CreateInstance( OID_TCP_CONNECTOR );
	if( connector == NULL ) {
		return 0;
	}

	// if initiate instance failed, reutrn;
	if( !CInstanceUtility::InitiateInstance(connector) ) {
		return 0;
	}

	U64 result = 0;
	CInterface<ITcpConnectorController> segment;
	if( segment.Mount(connector, IID_TCP_CONNECTOR_CONTROLLER) )
	{
		if( segment -> Open(hs, GetIOMold()) )
		{
			CInterface<IEventEmitter> emitter;
			if( emitter.Mount(this, IID_EVENT_EMITTER) )
			{
				tagEvent msg;
				msg.handle = EID_CONNECTION_ESTABLISHED;
				msg.source = CInstanceUtility::GetInstanceName( nest );
				msg.append = result = connector -> GetName();
				emitter -> Report( msg );
			}
		}
	}

	// if failed, shutdown connector's life;
	if( !result ) {
		CInstanceUtility::ShutdownInstance( connector );
	}

	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpListenerController::Update() 
{
    //TODO Auto-generated method stub
	// not use rightnow
}

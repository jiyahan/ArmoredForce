#include "CTcpConnectorController.h"
#include "CTcpNetworkService.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/ITcpIOModel.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IEventEmitter.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpConnectorController::CTcpConnectorController() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
active(false),iomold(0),socket(INVALID_SOCKET)
{
}

atom::CTcpConnectorController::~CTcpConnectorController() 
{
	Shut();
}

int atom::CTcpConnectorController::IncRef() 
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

int atom::CTcpConnectorController::DecRef() 
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

int atom::CTcpConnectorController::GetRef() 
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

atom::IInterface * atom::CTcpConnectorController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpConnectorController::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CTcpConnectorController::Open(const char * host, U16 port, U32 mold) 
{
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
	region.Enter();

	// get io model's interface;
	CInterface<ITcpIOModel> segment;
	if( segment.Mount(model, IID_TCP_IO_MODEL) )
	{
		socket = segment -> Create();
		if( INVALID_SOCKET != socket )
		{
			iomold = mold;

			// bind flush device and io model
			CInterface<ITcpConnectorFlushDevice> device;
			if( device.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
				device -> Bind( iomold );
			}

			// prepare domain structure;
			tagDomain target;
			target.host = host;
			target.port = port;

			// attach connector to io model, if succeed, try to 
			// receive peer message.
			if( segment -> Attach (object) &&
				segment -> Connect(object, target) ) {
				active = true;
				result = segment -> Receive( object );
			}

			// if succeeded, update local and peer address and port.
			if( result ) {
				Update();
			}

			// if failed, detach connector from io model, and close
			// socket, clear class member arguments, finally, reset
			// flush device, detach with io model.
			else
			{
				segment -> Detach( object );
				segment -> Remove( socket );

				active = false;
				socket = INVALID_SOCKET;
				iomold = 0;

				CInterface<ITcpConnectorFlushDevice> device;
				if( device.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
					device -> Reset();
				}
			}
		}
	}

	// leave critical section;
	region.Leave();

	// if succeeded, report connector ready event
	if( result )
	{
		CInterface<IEventEmitter> emitter;
		if( emitter.Mount(this, IID_EVENT_EMITTER) )
		{
			tagEvent msg;
			msg.handle = EID_CONNECTION_READY;
			msg.source = object;
			emitter -> Report( msg );
		}
	}
    return result;
}

bool atom::CTcpConnectorController::Open(SOCKET hs, U32 io) 
{
	if( hs == INVALID_SOCKET || !io || !nest ) {
		return 0;
	}

	// if io model is not valid, return false;
	CObjectPtr model = CTcpNetworkService::GetInstance() -> GetModel( io );
	if( model == NULL ) {
		return false;
	}

	bool result = false;
	U64  object = CInstanceUtility::GetInstanceName( nest );
	region.Enter();

	// get io model's interface;
	CInterface<ITcpIOModel> segment;
	if( segment.Mount(model, IID_TCP_IO_MODEL) )
	{
		socket = hs;
		iomold = io;

		// bind flush device and io model
		CInterface<ITcpConnectorFlushDevice> device;
		if( device.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
			device -> Bind( iomold );
		}

		// attach connector to io model, if succeed, try to 
		// receive peer message.
		if( segment -> Attach(object) ) {
			active = true;
			result = segment -> Receive( object );
		}

		// if succeeded, update local and peer address and port.
		if( result ) {
			Update();
		}

		// if failed, detach connector from io model, and close
		// socket, clear class member arguments, finally, reset
		// flush device, detach with io model.
		else
		{
			segment -> Detach( object );
			segment -> Remove( socket );

			active = false;
			socket = INVALID_SOCKET;
			iomold = 0;

			CInterface<ITcpConnectorFlushDevice> device;
			if( device.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
				device -> Reset();
			}
		}
	}

	// leave critical section;
	region.Leave();

	// if succeeded, report connector ready event
	if( result )
	{
		CInterface<IEventEmitter> emitter;
		if( emitter.Mount(this, IID_EVENT_EMITTER) )
		{
			tagEvent msg;
			msg.handle = EID_CONNECTION_READY;
			msg.source = object;
			emitter -> Report( msg );
		}
	}
    return result;
}

void atom::CTcpConnectorController::Shut() 
{
	bool result = false;
	U64  object = CInstanceUtility::GetInstanceName( nest );
	region.Enter();

	// if connector already open;
	if( active )
	{
		active = false;
		result = true;

		CObjectPtr model =
			CTcpNetworkService::GetInstance() -> GetModel( iomold );
		if( model )
		{
			CInterface<ITcpIOModel> segment;
			if( segment.Mount(model, IID_TCP_IO_MODEL) )
			{
				segment -> Detach( object );
				segment -> Remove( socket );

				domain.host.clear();
				domain.port = 0;

				remote.host.clear();
				remote.port = 0;

				socket = INVALID_SOCKET;
				iomold = 0;

				CInterface<ITcpConnectorFlushDevice> device;
				if( device.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
					device -> Reset();
				}
			}
		}
	}

	// leave critical section;
	region.Leave();

	// if succeeded, emit close event;
	if( result )
	{
		CInterface<IEventEmitter> emitter;
		if( emitter.Mount(this, IID_EVENT_EMITTER) )
		{
			tagEvent msg;
			msg.handle = EID_CONNECTION_CLOSED;
			msg.source = object;
			emitter -> Report( msg );
		}
	}
}

bool atom::CTcpConnectorController::GetActive() 
{
	CCriticalSectionScope scope( region );
	return active;
}

SOCKET atom::CTcpConnectorController::GetSocket() 
{
	CCriticalSectionScope scope( region );
	return socket;
}

U32 atom::CTcpConnectorController::GetIOMold() 
{
	CCriticalSectionScope scope( region );
	return iomold;
}

atom::a_string atom::CTcpConnectorController::GetSelfAddress() 
{
	CCriticalSectionScope scope( region );
	return domain.host;
}

U16 atom::CTcpConnectorController::GetSelfPort() 
{
	CCriticalSectionScope scope( region );
	return domain.port;
}

atom::a_string atom::CTcpConnectorController::GetPeerAddress() 
{
	CCriticalSectionScope scope( region );
	return remote.host;
}

U16 atom::CTcpConnectorController::GetPeerPort() 
{
	CCriticalSectionScope scope( region );
	return remote.port;
}

void atom::CTcpConnectorController::Update() 
{
	sockaddr_in peer;
	sockaddr_in self;

	#ifdef _WIN32
	int size = static_cast<int>( sizeof(sockaddr_in) );
	#endif
		
	#ifdef __linux 
	socklen_t size = static_cast<socklen_t>( sizeof(sockaddr_in) );
	#endif

	#ifdef __APPLE__
	socklen_t size = static_cast<socklen_t>( sizeof(sockaddr_in) );
	#endif

	if( getsockname( GetSocket(), reinterpret_cast<sockaddr*>(&self), &size ) == 0 )
	{
		const char * addr = inet_ntoa( self.sin_addr );
		if( addr )
		{
			domain.host = addr;
			domain.port = ntohs( self.sin_port );
		}
	}

	if( getpeername( GetSocket(), reinterpret_cast<sockaddr*>(&peer), &size ) == 0 )
	{
		const char * addr = inet_ntoa( peer.sin_addr );
		if( addr )
		{
			remote.host = addr;
			remote.port = ntohs( peer.sin_port );
		}
	}
}

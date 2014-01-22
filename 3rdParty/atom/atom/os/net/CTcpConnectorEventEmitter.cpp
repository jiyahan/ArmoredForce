#include "CTcpConnectorEventEmitter.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IEventReceiver.h"
#include "../../interface/ITcpConnectionController.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpConnectorEventEmitter::CTcpConnectorEventEmitter() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CTcpConnectorEventEmitter::~CTcpConnectorEventEmitter() 
{
}

int atom::CTcpConnectorEventEmitter::IncRef() 
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

int atom::CTcpConnectorEventEmitter::DecRef() 
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

int atom::CTcpConnectorEventEmitter::GetRef() 
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

atom::IInterface * atom::CTcpConnectorEventEmitter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpConnectorEventEmitter::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CTcpConnectorEventEmitter::Attach(U64 object) 
{
	CObjectPtr instance = CInstanceFactory::GetInstance() -> Inquire( object );
	return Attach( instance );
}

bool atom::CTcpConnectorEventEmitter::Attach(CObjectPtr & object) 
{
	bool result = false;
	CCriticalSectionScope scope( section );
	if( object && node == NULL ) {
		node = object; result = true;
	}
    return result;
}
void atom::CTcpConnectorEventEmitter::Detach() 
{
	CCriticalSectionScope scope( section );
    node = NULL;
}

bool atom::CTcpConnectorEventEmitter::Report(const tagEvent & value) 
{
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

bool atom::CTcpConnectorEventEmitter::Report(const char * target, const tagEvent & value) 
{
	bool result = false;
	if( target )
	{
		tagEvent e( value ); e.target = target;
		result = Report( e );
	}
	return result;
}

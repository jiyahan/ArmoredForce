#include "CTcpListenerLife.h"
#include "../../interface/ITcpListenerController.h"
#include "../../interface/IEventEmitter.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpListenerLife::CTcpListenerLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CTcpListenerLife::~CTcpListenerLife() 
{
}

int atom::CTcpListenerLife::IncRef() 
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

int atom::CTcpListenerLife::DecRef() 
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

int atom::CTcpListenerLife::GetRef() 
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

atom::IInterface * atom::CTcpListenerLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpListenerLife::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CTcpListenerLife::Initiate() 
{
    return true;
}

bool atom::CTcpListenerLife::Shutdown() 
{
	CInterface<ITcpListenerController> segment_1;
	if( segment_1.Mount(this, IID_TCP_LISTENER_CONTROLLER) ) {
		segment_1 -> Shut();
	}

	CInterface<IEventEmitter> segment_2;
	if( segment_2.Mount(this, IID_EVENT_EMITTER) ) {
		segment_2 -> Detach();
	}
    return true;
}

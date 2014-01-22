#include "CTcpListener.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpListener::CTcpListener()
{
	controller   .SetNest( this );
	emitter      .SetNest( this );
	life         .SetNest( this );
}

atom::CTcpListener::~CTcpListener() 
{
}

const char * atom::CTcpListener::ToString() 
{
	static char name[] = "Tcp Listener";
    return name;
}

atom::IInterface * atom::CTcpListener::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_EVENT_EMITTER:
		if( emitter      .IncRef() )
			result = & emitter;
        break;
	case IID_INSTANCE_LIFE:
		if( life         .IncRef() )
			result = & life;
        break;
	case IID_TCP_CONNECTION_CONTROLLER:
	case IID_TCP_LISTENER_CONTROLLER:
		if( controller   .IncRef() )
			result = & controller;
		break;
    }
    return result;
}

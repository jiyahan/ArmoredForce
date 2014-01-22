#include "CConnectorStub.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectorStub::CConnectorStub() 
{
    receiver  .SetNest( this );
    emitter   .SetNest( this );
    frame     .SetNest( this );
    maintain  .SetNest( this );
    life      .SetNest( this );
    heartbeat .SetNest( this );
    statistics.SetNest( this );
}

electron::CConnectorStub::~CConnectorStub() 
{
}

const char * electron::CConnectorStub::ToString() 
{
    static char name[] = "Connector Stub";
    return name;
}

IInterface * electron::CConnectorStub::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_EVENT_EMITTER:
		if( emitter      .IncRef() )
			result = & emitter;
        break;
    case IID_EVENT_RECEIVER:
        if( receiver     .IncRef() )
            result = & receiver;
        break;
	case IID_INSTANCE_LIFE:
		if( life         .IncRef() )
			result = & life;
        break;
    case IID_MAINTAINABLE:
		if( maintain     .IncRef() )
			result = & maintain;
        break;
    case IID_CONNECTOR_STUB_FRAME:
		if( frame        .IncRef() )
			result = & frame;
        break;
    case IID_CONNECTOR_STUB_HEART_BEAT:
		if( heartbeat    .IncRef() )
            result = & heartbeat;
        break;
    case IID_CONNECTOR_STUB_STATISTICS:
        if( statistics   .IncRef() )
            result = & statistics;
        break;
    }
    return result;
}

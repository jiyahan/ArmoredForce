#include "CTcpConnector.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpConnector::CTcpConnector()
{
	controller   .SetNest( this );
	emitter      .SetNest( this );
	flush        .SetNest( this );
	life         .SetNest( this );
	import_stream.SetNest( this );
	export_stream.SetNest( this );
}

atom::CTcpConnector::~CTcpConnector() 
{
}

const char * atom::CTcpConnector::ToString() 
{
	static char name[] = "Tcp Connector";
    return name;
}

atom::IInterface * atom::CTcpConnector::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_EVENT_EMITTER:
		if( emitter      .IncRef() )
			result = & emitter;
        break;
	case IID_IMPORT_STREAM:
		if( import_stream.IncRef() )
			result = & import_stream;
        break;
	case IID_EXPORT_STREAM:
		if( export_stream.IncRef() )
			result = & export_stream;
        break;
	case IID_INSTANCE_LIFE:
		if( life         .IncRef() )
			result = & life;
        break;
	case IID_TCP_CONNECTION_CONTROLLER:
	case IID_TCP_CONNECTOR_CONTROLLER:
		if( controller   .IncRef() )
			result = & controller;
		break;
	case IID_FLUSH_DEVICE:
	case IID_TCP_CONNECTOR_FLUSH_DEVICE:
		if( flush        .IncRef() )
			result = & flush;
		break;
    }
    return result;
}

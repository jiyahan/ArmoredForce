#include "CTcpConnector.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpConnector.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpConnector.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnector::CTcpConnector()
{
    //TODO Auto-generated method stub
	controller   .SetNest( this );
	emitter      .SetNest( this );
	flush        .SetNest( this );
	life         .SetNest( this );
	import_stream.SetNest( this );
	export_stream.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnector::~CTcpConnector() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CTcpConnector::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Tcp Connector";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpConnector::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

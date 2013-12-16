#include "CTcpListener.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpListener.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpListener.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpListener::CTcpListener()
{
    //TODO Auto-generated method stub
	controller   .SetNest( this );
	emitter      .SetNest( this );
	life         .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpListener::~CTcpListener() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CTcpListener::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Tcp Listener";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpListener::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

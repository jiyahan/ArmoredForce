#include "CEventSpace.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CEventSpace.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventSpace.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventSpace::CEventSpace()
{
    //TODO Auto-generated method stub
	controller.SetNest( this );
	container .SetNest( this );
	listener  .SetNest( this );
	life      .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventSpace::~CEventSpace() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CEventSpace::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Event Space";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CEventSpace::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_EVENT_RECEIVER:
	case IID_EVENT_SPACE_CONTROLLER:
		if( controller.IncRef() )
			result = & controller;
        break;
	case IID_INSTANCE_CONTAINER:
		if( container .IncRef() )
			result = & container;
        break;
	case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener  .IncRef() )
			result = & listener;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
        break;
    }
    return result;
}

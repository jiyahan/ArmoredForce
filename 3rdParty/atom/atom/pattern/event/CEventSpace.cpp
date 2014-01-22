#include "CEventSpace.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CEventSpace::CEventSpace()
{
	controller.SetNest( this );
	container .SetNest( this );
	listener  .SetNest( this );
	life      .SetNest( this );
}

atom::CEventSpace::~CEventSpace() 
{
}

const char * atom::CEventSpace::ToString() 
{
	static char name[] = "Event Space";
    return name;
}

atom::IInterface * atom::CEventSpace::QueryInterface(U32 iid) 
{
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

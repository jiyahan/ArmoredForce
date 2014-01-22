#include "CMaintainer.h"
#include "../enumeration/THREAD_PRIORITY.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CMaintainer::CMaintainer() 
{
    thread   .SetNest( this );
    container.SetNest( this );
    listener .SetNest( this );
    timeline .SetNest( this );
	life     .SetNest( this );
}

atom::CMaintainer::~CMaintainer() 
{
}

atom::IInterface * atom::CMaintainer::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_INSTANCE_CONTAINER:
        result = & container;
        break;
    case IID_INSTANCE_CONTAINER_LISTENER:
        result = & listener;
        break;
    case IID_MAINTAINER_TIMELINE:
        result = & timeline;
        break;
	case IID_INSTANCE_LIFE:
		result = & life;
		break;
	case IID_THREAD_CONTROL:
		result = & thread;
		break;
    }
    return result;
}

bool atom::CMaintainer::Attach(CObjectPtr & value) 
{
    return container.Insert( value );
}

void atom::CMaintainer::Detach(CObjectPtr & value) 
{
	if( value ) {
		container.Remove( value -> GetName() );
	} 
}

void atom::CMaintainer::Detach(U64 name) 
{
    container.Remove( name );
}

bool atom::CMaintainer::Initiate() 
{
	return life.Initiate();
}

bool atom::CMaintainer::Shutdown() 
{
	return life.Shutdown();
}

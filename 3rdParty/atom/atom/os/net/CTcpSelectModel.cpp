#include "CTcpSelectModel.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpSelectModel::CTcpSelectModel()
{
	model    .SetNest( this );
	thread   .SetNest( this );
	life     .SetNest( this );
	container.SetNest( this );
	listener .SetNest( this );
}

atom::CTcpSelectModel::~CTcpSelectModel() 
{
}

const char * atom::CTcpSelectModel::ToString() 
{
	static char name[] = "Tcp Select Model";
    return name;
}

atom::IInterface * atom::CTcpSelectModel::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_CONTAINER:
		if( container  .IncRef() )
			result = & container;
        break;
	case IID_INSTANCE_CONTAINER_LISTENER:
		if( listener   .IncRef() )
			result = & listener;
        break;
	case IID_INSTANCE_LIFE:
		if( life       .IncRef() )
			result = & life;
        break;
	case IID_THREAD_CONTROL:
		if( thread     .IncRef() )
			result = & thread;
        break;
	case IID_TCP_IO_MODEL:
	case IID_TCP_SELECT_IO_MODEL:
		if( model      .IncRef() )
			result = & model;
		break;
    }
    return result;
}

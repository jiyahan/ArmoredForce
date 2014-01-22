#include "CTcpKQueueModel.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpKQueueModel::CTcpKQueueModel() 
{
	implement.SetNest( this );
	threads  .SetNest( this );
	life     .SetNest( this );
	container.SetNest( this );
	listener .SetNest( this );
	alias    .SetNest( this );
}

atom::CTcpKQueueModel::~CTcpKQueueModel() 
{
}

const char * atom::CTcpKQueueModel::ToString() 
{
	static char name[] = "Tcp KQueue Model";
    return name;
}

atom::IInterface * atom::CTcpKQueueModel::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_ALIAS_CONTAINER:
		if( alias      .IncRef() )
			result = & alias;
        break;
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
	case IID_MULTI_THREAD_CONTROL:
		if( threads    .IncRef() )
			result = & threads;
        break;
	case IID_TCP_IO_MODEL:
	case IID_TCP_KQUEUE_IO_MODEL:
		if( implement  .IncRef() )
			result = & implement;
		break;
    }
    return result;
}

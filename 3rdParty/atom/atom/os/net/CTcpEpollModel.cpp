#include "CTcpEpollModel.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpEpollModel::CTcpEpollModel() 
{
	implement.SetNest( this );
	threads  .SetNest( this );
	life     .SetNest( this );
	container.SetNest( this );
	listener .SetNest( this );
}

atom::CTcpEpollModel::~CTcpEpollModel() 
{
}

const char * atom::CTcpEpollModel::ToString() 
{
	static char name[] = "Tcp Epoll Model";
    return name;
}

atom::IInterface * atom::CTcpEpollModel::QueryInterface(U32 iid) 
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
	case IID_MULTI_THREAD_CONTROL:
		if( threads    .IncRef() )
			result = & threads;
        break;
	case IID_TCP_IO_MODEL:
	case IID_TCP_EPOLL_IO_MODEL:
		if( implement  .IncRef() )
			result = & implement;
		break;
    }
    return result;
}

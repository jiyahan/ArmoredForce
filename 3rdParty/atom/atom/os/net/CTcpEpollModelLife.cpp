#include "CTcpEpollModelLife.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpEpollModelLife::CTcpEpollModelLife() : 
nest(NULL)
{
}

atom::CTcpEpollModelLife::~CTcpEpollModelLife() 
{
}

int atom::CTcpEpollModelLife::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int atom::CTcpEpollModelLife::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int atom::CTcpEpollModelLife::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

atom::IInterface * atom::CTcpEpollModelLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpEpollModelLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpEpollModelLife::Initiate() 
{
	bool result = false;
	CInterface<ITcpEpollIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

bool atom::CTcpEpollModelLife::Shutdown() 
{
	bool result = false;
	CInterface<ITcpEpollIOModel> segment_0;
	if( segment_0.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		segment_0 -> PreShutdown();
	}

	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpEpollIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_EPOLL_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}
    return result;
}

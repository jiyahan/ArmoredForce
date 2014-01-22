#include "CTcpKQueueModelLife.h"
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpKQueueModelLife::CTcpKQueueModelLife() : 
nest(NULL)
{
}

atom::CTcpKQueueModelLife::~CTcpKQueueModelLife() 
{
}

int atom::CTcpKQueueModelLife::IncRef() 
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

int atom::CTcpKQueueModelLife::DecRef() 
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

int atom::CTcpKQueueModelLife::GetRef() 
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

atom::IInterface * atom::CTcpKQueueModelLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpKQueueModelLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpKQueueModelLife::Initiate() 
{
	bool result = false;
	CInterface<ITcpKQueueIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_KQUEUE_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

bool atom::CTcpKQueueModelLife::Shutdown() 
{
	bool result = false;
	CInterface<ITcpKQueueIOModel> segment_0;
	if( segment_0.Mount(this, IID_TCP_KQUEUE_IO_MODEL) ) {
		segment_0 -> PreShutdown();
	}

	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpKQueueIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_KQUEUE_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceAliasContainer<U32> > segment_3;
	if( segment_3.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
		segment_3 -> RemoveAll();
	}
    return result;
}

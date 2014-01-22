#include "CTcpIocpModelLife.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../interface/IMultiThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpIocpModelLife::CTcpIocpModelLife() : 
nest(NULL)
{
}

atom::CTcpIocpModelLife::~CTcpIocpModelLife() 
{
}

int atom::CTcpIocpModelLife::IncRef() 
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

int atom::CTcpIocpModelLife::DecRef() 
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

int atom::CTcpIocpModelLife::GetRef() 
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

atom::IInterface * atom::CTcpIocpModelLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpIocpModelLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpIocpModelLife::Initiate() 
{
	bool result = false;
	CInterface<ITcpIocpIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_IOCP_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

bool atom::CTcpIocpModelLife::Shutdown() 
{
	bool result = false;
	CInterface<ITcpIocpIOModel> segment_0;
	if( segment_0.Mount(this, IID_TCP_IOCP_IO_MODEL) ) {
		segment_0 -> PreShutdown();
	}

	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpIocpIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceAliasContainer<U32> > segment_3;
	if( segment_3.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
		segment_3 -> RemoveAll();
	}

	CInterface<IInstanceContainer> segment_4;
	if( segment_4.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_4 -> RemoveAll();
	}
    return result;
}

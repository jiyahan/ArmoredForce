#include "CTcpSelectModelLife.h"
#include "../../interface/ITcpSelectIOModel.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpSelectModelLife::CTcpSelectModelLife() : 
nest(NULL)
{
}

atom::CTcpSelectModelLife::~CTcpSelectModelLife() 
{
}

int atom::CTcpSelectModelLife::IncRef() 
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

int atom::CTcpSelectModelLife::DecRef() 
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

int atom::CTcpSelectModelLife::GetRef() 
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

atom::IInterface * atom::CTcpSelectModelLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpSelectModelLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CTcpSelectModelLife::Initiate() 
{
	bool result = false;
	CInterface<ITcpSelectIOModel> segment_1;
	if( segment_1.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_1 -> Initiate();
	}

	CInterface<IThreadControl> segment_2;
	if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_2 -> OnBegin() && result;
	}
    return result;
}

bool atom::CTcpSelectModelLife::Shutdown() 
{
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<ITcpSelectIOModel> segment_2;
	if( segment_2.Mount(this, IID_TCP_SELECT_IO_MODEL) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceContainer> segment_3;
	if( segment_3.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_3 -> RemoveAll();
	}
    return result;
}

#include "CEventSpaceLife.h"
#include "../../interface/IEventSpaceController.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CEventSpaceLife::CEventSpaceLife() : 
nest(NULL)
{
}

atom::CEventSpaceLife::~CEventSpaceLife() 
{
}

int atom::CEventSpaceLife::IncRef() 
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

int atom::CEventSpaceLife::DecRef() 
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

int atom::CEventSpaceLife::GetRef() 
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

atom::IInterface * atom::CEventSpaceLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventSpaceLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CEventSpaceLife::Initiate() 
{
	bool result = false;
	CInterface<IEventSpaceController> segment;
	if( segment.Mount(this, IID_EVENT_SPACE_CONTROLLER) ) {
		result = segment -> Initiate();
	}
    return result;
}

bool atom::CEventSpaceLife::Shutdown() 
{
	bool result = false;
	CInterface<IEventSpaceController> segment_1;
	if( segment_1.Mount(this, IID_EVENT_SPACE_CONTROLLER) ) {
		result = segment_1 -> Shutdown();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) {
		segment_2 -> RemoveAll();
	}
	return result;
}

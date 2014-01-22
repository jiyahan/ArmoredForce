#include "CEventServiceLife.h"
#include "../../interface/IThreadControl.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IEventServiceEntry.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CEventServiceLife::CEventServiceLife() : 
nest(NULL)
{
}

atom::CEventServiceLife::~CEventServiceLife() 
{
}

int atom::CEventServiceLife::IncRef() 
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

int atom::CEventServiceLife::DecRef() 
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

int atom::CEventServiceLife::GetRef() 
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

atom::IInterface * atom::CEventServiceLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventServiceLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CEventServiceLife::Initiate() 
{
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnBegin();
	}
    return result;
}

bool atom::CEventServiceLife::Shutdown() 
{
	bool result = false;
	CInterface<IThreadControl> segment_1;
	if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
		result = segment_1 -> OnClose();
	}

	CInterface<IInstanceContainer> segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_CONTAINER) ) 
	{
		CInterface<IEventServiceEntry> segment_3;
		if( segment_3.Mount(this, IID_EVENT_SERVICE_ENTRY) )
		{
			CU64Array indices;
			segment_2 -> Obtain( indices );

			for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
				segment_3 -> Remove( indices[i] );
			}
		}

		segment_2 -> RemoveAll();
	}
    return result;
}

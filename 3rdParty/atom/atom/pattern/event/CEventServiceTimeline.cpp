#include "CEventServiceTimeline.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IThreadControl.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CEventServiceTimeline::CEventServiceTimeline() : 
nest(NULL)
{
}

atom::CEventServiceTimeline::~CEventServiceTimeline() 
{
}

int atom::CEventServiceTimeline::IncRef() 
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

int atom::CEventServiceTimeline::DecRef() 
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

int atom::CEventServiceTimeline::GetRef() 
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

atom::IInterface * atom::CEventServiceTimeline::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventServiceTimeline::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CEventServiceTimeline::Mark(U64 time, U64 instance) 
{
    line.Mark( time, instance );

	CInterface<IThreadControl> segment;
	if( segment.Mount(this, IID_THREAD_CONTROL) ) {
		segment -> OnAwake();
	}
}

void atom::CEventServiceTimeline::Forward(U64 time, CU64Array & instances) 
{
    line.Forward( time, instances );
}

#include "CMaintainerTimeline.h"


atom::CMaintainerTimeline::CMaintainerTimeline() : 
nest(NULL)
{
}

atom::CMaintainerTimeline::~CMaintainerTimeline() 
{
}

int atom::CMaintainerTimeline::IncRef() 
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

int atom::CMaintainerTimeline::DecRef() 
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

int atom::CMaintainerTimeline::GetRef() 
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

atom::IInterface * atom::CMaintainerTimeline::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CMaintainerTimeline::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CMaintainerTimeline::Mark(U64 time, U64 instance) 
{
    line.Mark( time, instance );
}

void atom::CMaintainerTimeline::Forward(U64 time, CU64Array & instances) 
{
    line.Forward( time, instances );
}

#include "CMaintainerListener.h"
#include "../pattern/life/CInstanceLife.h"
#include "../os/timer/CMilisecondTimer.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IMaintainerTimeline.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CMaintainerListener::CMaintainerListener() : 
nest(NULL)
{
}

atom::CMaintainerListener::~CMaintainerListener() 
{
}

int atom::CMaintainerListener::IncRef() 
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

int atom::CMaintainerListener::DecRef() 
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

int atom::CMaintainerListener::GetRef() 
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

atom::IInterface * atom::CMaintainerListener::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CMaintainerListener::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void atom::CMaintainerListener::OnInsertInstance(CObjectPtr & instance) 
{
    if( instance )
    {
		CInstanceLife::GetInstance() -> Increase( instance -> GetName() );

        CInterface<IMaintainerTimeline> timeline;
        if( timeline.Mount(this, IID_MAINTAINER_TIMELINE) ) {
            timeline -> Mark( CMilisecondTimer::Now(), instance -> GetName() );
        }
    }
}

void atom::CMaintainerListener::OnRemoveInstance(CObjectPtr & instance) 
{
	if( instance )
	{
		CInstanceLife::GetInstance() -> Decrease( instance -> GetName() );
	}
}

#include "CInstanceContainerListener.h"
#include "../life/CInstanceLife.h"


atom::CInstanceContainerListener::CInstanceContainerListener() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CInstanceContainerListener::~CInstanceContainerListener() 
{
}

int atom::CInstanceContainerListener::IncRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

int atom::CInstanceContainerListener::DecRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

int atom::CInstanceContainerListener::GetRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

atom::IInterface * atom::CInstanceContainerListener::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceContainerListener::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void atom::CInstanceContainerListener::OnInsertInstance(CObjectPtr & instance) 
{
    if( instance )
    {
		CInstanceLife::GetInstance() -> Increase( instance -> GetName() );
    }
}

void atom::CInstanceContainerListener::OnRemoveInstance(CObjectPtr & instance) 
{
	if( instance )
	{
		CInstanceLife::GetInstance() -> Decrease( instance -> GetName() );
	}
}

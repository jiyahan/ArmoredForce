#include "CEventEmitter.h"
#include "CEventService.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IEventSpaceController.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"


atom::CEventEmitter::CEventEmitter() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
node(0)
{
}

atom::CEventEmitter::~CEventEmitter() 
{
}

int atom::CEventEmitter::IncRef() 
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

int atom::CEventEmitter::DecRef() 
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

int atom::CEventEmitter::GetRef() 
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

atom::IInterface * atom::CEventEmitter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventEmitter::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CEventEmitter::Attach(U64 space) 
{
	bool result = false;
	if( node == 0 && space ) {
		node = space; result = true;
	}
    return result;
}

bool atom::CEventEmitter::Attach(CObjectPtr & object) 
{
	bool result = false;
	if( object &&
		object -> GetType() == OID_EVENT_SPACE ) 
	{
		result = Attach( object -> GetName() );
	}
	return result;
}

void atom::CEventEmitter::Detach() 
{
    node = 0;
}

bool atom::CEventEmitter::Report(const tagEvent & value) 
{
	bool result = false; U64 space = node;
	if( space )
	{
		CInterface<IInstanceContainer> segment_1;
		if( segment_1.Mount( CEventService::GetInstance(), IID_INSTANCE_CONTAINER ) )
		{
			CObjectPtr object = segment_1 -> Obtain( space );
			if( object )
			{
				CInterface<IEventSpaceController> segment_2;
				if( segment_2.Mount(object, IID_EVENT_SPACE_CONTROLLER) ) {
                    result = segment_2 -> OnEvent( value );
				}
			}
		}
	}
    return result;
}

bool atom::CEventEmitter::Report(const char * target, const tagEvent & value) 
{
	bool result = false;
	if( target )
	{
		tagEvent e( value ); e.target = target;
		result = Report( e );
	}
	return result;
}

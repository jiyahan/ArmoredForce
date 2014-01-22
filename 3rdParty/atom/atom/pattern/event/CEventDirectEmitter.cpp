#include "CEventDirectEmitter.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../interface/IEventReceiver.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CEventDirectEmitter::CEventDirectEmitter() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CEventDirectEmitter::~CEventDirectEmitter() 
{
}

int atom::CEventDirectEmitter::IncRef() 
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

int atom::CEventDirectEmitter::DecRef() 
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

int atom::CEventDirectEmitter::GetRef() 
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

atom::IInterface * atom::CEventDirectEmitter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventDirectEmitter::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CEventDirectEmitter::Attach(U64 object) 
{
	CObjectPtr instance = CInstanceFactory::GetInstance() -> Inquire( object );
	return Attach( instance );
}

bool atom::CEventDirectEmitter::Attach(CObjectPtr & object) 
{
	bool result = false;
	CCriticalSectionScope scope( section );
	if( object && node == NULL ) {
		node = object; result = true;
	}
    return result;
}

void atom::CEventDirectEmitter::Detach() 
{
	CCriticalSectionScope scope( section );
    node = NULL;
}

bool atom::CEventDirectEmitter::Report(const tagEvent & value) 
{
	bool result = false; 
	CCriticalSectionScope scope( section );
	if( node )
	{
		CInterface<IEventReceiver> segment;
		if( segment.Mount(node, IID_EVENT_RECEIVER) ) {
			result = segment -> OnEvent( value );
		}
	}
	return result;
}

bool atom::CEventDirectEmitter::Report(const char * target, const tagEvent & value) 
{
	bool result = false;
	if( target )
	{
		tagEvent e( value ); e.target = target;
		result = Report( e );
	}
	return result;
}

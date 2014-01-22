#include "CInstanceFactoryAllocator.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceAllocator.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceFactoryAllocator::CInstanceFactoryAllocator() : 
nest(NULL)
{
}

atom::CInstanceFactoryAllocator::~CInstanceFactoryAllocator() 
{
}

int atom::CInstanceFactoryAllocator::IncRef() 
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

int atom::CInstanceFactoryAllocator::DecRef() 
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

int atom::CInstanceFactoryAllocator::GetRef() 
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

atom::IInterface * atom::CInstanceFactoryAllocator::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceFactoryAllocator::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CInstanceFactoryAllocator::Attach(CObjectPtr & allocator) 
{
	bool result = false;
	if( allocator )
	{
		CInterface<IInstanceAllocator> segment;
		if( segment.Mount(allocator, IID_INSTANCE_ALLOCATOR) )
		{
			for( size_t i = 0; i < ALLOCATOR_TOTAL; ++ i )
			{
				if( list[i].lower == 0 &&
					list[i].upper == 0 &&
					list[i].point == NULL ) 
				{
					list[i].point = allocator;
					segment -> Confine( list[i].lower, list[i].upper );
					result = true; break;
				}
			}
		}
	}
    return result;
}

bool atom::CInstanceFactoryAllocator::Detach(CObjectPtr & allocator) 
{
	bool result = false;
	if( allocator )
	{
		for( size_t i = 0; i < ALLOCATOR_TOTAL; ++ i )
		{
			if( list[i].point == allocator )  {
				result = true; 
				list[i].Clear(); break;
			}
		}
	}
    return result;
}

atom::CReferencedObject * atom::CInstanceFactoryAllocator::Product(U32 type) 
{
	CReferencedObject * result = NULL;
	if( type )
	{
		// find correct allocator to product this object;
		for( size_t i = 0; i < ALLOCATOR_TOTAL; ++ i )
		{
			if( type >= list[i].lower &&
				type <= list[i].upper )
			{
				CInterface<IInstanceAllocator> segment;
				if( segment.Mount(list[i].point, IID_INSTANCE_ALLOCATOR) ) {
					result = segment -> Product( type );
				}
				break;
			}
		}

		// if instance created, set instance's type;
		if( result ) {
			result -> SetType( type );
		}
	}
    return result;
}

void atom::CInstanceFactoryAllocator::Destroy(CReferencedObject * value) 
{
	if( value )
	{
		bool succeed = false;
		U32 type = value -> GetType();

		// find correct allocator to destroy this object;
		for( size_t i = 0; i < ALLOCATOR_TOTAL; ++ i )
		{
			if( type >= list[i].lower &&
				type <= list[i].upper )
			{
				CInterface<IInstanceAllocator> segment;
				if( segment.Mount(list[i].point, IID_INSTANCE_ALLOCATOR) ) {
					segment -> Destroy( value );
					succeed = true;
				}
				break;
			}
		}

		// if not destroy succeed, try to delete this object manual;
		if( succeed == false ) {
			SAFE_DELETE( value );
		}
	}
}

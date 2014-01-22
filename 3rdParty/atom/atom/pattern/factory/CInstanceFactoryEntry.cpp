#include "CInstanceFactoryEntry.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceFactoryAllocator.h"
#include "../../enumeration/OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceFactoryEntry::CInstanceFactoryEntry() : 
nest(NULL)
{
	// keep reserved object's type and name are the same;
    name.Assign( OBJECT_ID_RESERVE + 1 );
}

atom::CInstanceFactoryEntry::~CInstanceFactoryEntry() 
{
}

int atom::CInstanceFactoryEntry::IncRef() 
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

int atom::CInstanceFactoryEntry::DecRef() 
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

int atom::CInstanceFactoryEntry::GetRef() 
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

atom::IInterface * atom::CInstanceFactoryEntry::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceFactoryEntry::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CInstanceFactoryEntry::Initiate() 
{
	CCriticalSectionScope scope( scopes );
	active = true;
    return active;
}

bool atom::CInstanceFactoryEntry::Shutdown() 
{
	CCriticalSectionScope scope( scopes );
	active = false;

	CU64Array indices;
	instances.Obtain( indices );

	bool exist = false;
	for( size_t i = 0, j = indices.size(); i < j; ++ i )
	{
		// force to delete all unhandled instances;
		CReferencedObject * instance = instances.Remove( indices[i], exist, true );
		if( instance )
		{
			#ifdef _DEBUG
			#endif

			SAFE_DELETE( instance );
		}
	}

	indices.clear();
	remove.Obtain( indices );
    return true;
}

U64 atom::CInstanceFactoryEntry::Product(U32 type) 
{
	U64 result = 0;
	if( type )
	{
		CInterface<IInstanceFactoryAllocator> segment;
		if( segment.Mount(this, IID_INSTANCE_FACTORY_ALLOCATOR) )
		{
			CReferencedObject * instance = segment -> Product( type );
			if( instance )
			{
				// alloc instance name;
				instance -> SetName( name.Increase() );

				// insert instance into container;
				if( instances.Insert(instance) ) {
					result = instance -> GetName();
				}

				// if this object not succeed prepare, destory it.
				if( !result ) {
					segment -> Destroy( instance );
				}
			}
		}
	}
	return result;
}

atom::CObjectPtr atom::CInstanceFactoryEntry::Inquire(U64 name) 
{
	CObjectPtr result;
	if( name ) {
		result = instances.Obtain( name );
	}
	return result;
}

bool atom::CInstanceFactoryEntry::Destroy(U64 name) 
{
	bool result = false;
	if( name )
	{
		bool exist = false;
		CReferencedObject * instance =
			instances.Remove( name, exist, false );

		// if instance exist, than continue;
		if( exist )
		{
			result = true;
			if( instance )
			{
				// instance reference count is zero, can remove;
				CInterface<IInstanceFactoryAllocator> segment;
				if( segment.Mount(this, IID_INSTANCE_FACTORY_ALLOCATOR) ) {
					segment -> Destroy( instance );
				}
			}
			else
			{
				// instance reference count is not zero, insert queue;
				remove.Insert( name );
			}
		}
	}
    return result;
}

void atom::CInstanceFactoryEntry::Recycle() 
{
	// this critical section will visited by only two area, 
	// one is maintain thread, and second is main thread 
	// initial or shutdown function;
	CCriticalSectionScope scope( scopes );
	if( active )
	{
		CU64Array indices;
		remove.Obtain( indices );

		for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
			Destroy( indices[i] );
		}
	}
}

#include "CInstanceFactoryEntry.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceFactoryAllocator.h"
#include "../../enumeration/OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceFactoryEntry.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactoryEntry.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactoryEntry::CInstanceFactoryEntry() : 
nest(NULL)
{
    //TODO Auto-generated method stub
	// keep reserved object's type and name are the same;
    name.Assign( OBJECT_ID_RESERVE + 1 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactoryEntry::~CInstanceFactoryEntry() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactoryEntry::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactoryEntry::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactoryEntry::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CInstanceFactoryEntry::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceFactoryEntry::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactoryEntry::Initiate() 
{
    //TODO Auto-generated method stub
	CCriticalSectionScope scope( scopes );
	active = true;
    return active;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactoryEntry::Shutdown() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceFactoryEntry::Product(U32 type) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceFactoryEntry::Inquire(U64 name) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	if( name ) {
		result = instances.Obtain( name );
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactoryEntry::Destroy(U64 name) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceFactoryEntry::Recycle() 
{
    //TODO Auto-generated method stub
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

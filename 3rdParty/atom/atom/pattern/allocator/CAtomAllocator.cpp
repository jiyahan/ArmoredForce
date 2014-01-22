#include "CAtomAllocator.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"


atom::CAtomAllocator::CAtomAllocator() 
{
	allocator.SetNest( this );
}

atom::CAtomAllocator::~CAtomAllocator() 
{
}

void atom::CAtomAllocator::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CAtomAllocator::GetName() 
{
	return OID_ATOM_ALLOCATOR;
}

void atom::CAtomAllocator::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CAtomAllocator::GetType() 
{
	return OID_ATOM_ALLOCATOR;
}

const char * atom::CAtomAllocator::ToString() 
{
	static char name[] = "Atom Allocator";
    return name;
}

int atom::CAtomAllocator::IncRef() 
{
	return counter.Increase();
}

int atom::CAtomAllocator::DecRef() 
{
	return counter.Decrease();
}

int atom::CAtomAllocator::GetRef() 
{
	return counter.GetReference();
}

atom::IInterface * atom::CAtomAllocator::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_ALLOCATOR:
		if( allocator.IncRef() )
			result = & allocator;
        break;
    }
    return result;
}

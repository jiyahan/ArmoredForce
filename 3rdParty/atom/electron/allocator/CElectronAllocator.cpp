#include "CElectronAllocator.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CElectronAllocator::CElectronAllocator() 
{
	allocator.SetNest( this );
}

electron::CElectronAllocator::~CElectronAllocator() 
{
}

void electron::CElectronAllocator::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 electron::CElectronAllocator::GetName() 
{
    return OID_ELECTRON_ALLOCATOR;
}

void electron::CElectronAllocator::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 electron::CElectronAllocator::GetType() 
{
    return OID_ELECTRON_ALLOCATOR;
}

const char * electron::CElectronAllocator::ToString() 
{
    static char name[] = "Electron Allocator";
    return name;
}

int electron::CElectronAllocator::IncRef() 
{
    return counter.Increase();
}

int electron::CElectronAllocator::DecRef() 
{
    return counter.Decrease();
}

int electron::CElectronAllocator::GetRef() 
{
    return counter.GetReference();
}

IInterface * electron::CElectronAllocator::QueryInterface(U32 iid) 
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

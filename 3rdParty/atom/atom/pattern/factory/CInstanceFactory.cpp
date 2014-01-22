#include "CInstanceFactory.h"
#include "../../maintainer/CMaintainer.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceFactory::CInstanceFactory() 
{
	allocator .SetNest( this );
	entry     .SetNest( this );
	maintainer.SetNest( this );
	life      .SetNest( this );
}

atom::CInstanceFactory::~CInstanceFactory() 
{
}

bool atom::CInstanceFactory::Initiate() 
{
	return life.Initiate();
}

bool atom::CInstanceFactory::Shutdown() 
{
	return life.Shutdown();
}

void atom::CInstanceFactory::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CInstanceFactory::GetName() 
{
	// keep reserved object's type and name are the same;
	return OID_INSTANCE_FACTORY;
}

void atom::CInstanceFactory::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CInstanceFactory::GetType() 
{
	// keep reserved object's type and name are the same;
	return OID_INSTANCE_FACTORY;
}

const char * atom::CInstanceFactory::ToString() 
{
	static char name[] = "Instance Factory";
    return name;
}

int atom::CInstanceFactory::IncRef() 
{
	return counter.Increase();
}

int atom::CInstanceFactory::DecRef() 
{
	return counter.Decrease();
}

int atom::CInstanceFactory::GetRef() 
{
	return counter.GetReference();
}

atom::IInterface * atom::CInstanceFactory::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_FACTORY_ALLOCATOR:
		if( allocator .IncRef() )
			result = & allocator;
        break;
	case IID_INSTANCE_FACTORY_ENTRY:
		if( entry     .IncRef() )
			result = & entry;
        break;
	case IID_MAINTAINABLE:
		if( maintainer.IncRef() )
			result = & maintainer;
        break;
	case IID_INSTANCE_LIFE:
		if( life      .IncRef() )
			result = & life;
		break;
    }
    return result;
}

bool atom::CInstanceFactory::Attach(CObjectPtr & value) 
{
	return allocator.Attach( value );
}

bool atom::CInstanceFactory::Detach(CObjectPtr & value) 
{
	return allocator.Detach( value );
}

U64 atom::CInstanceFactory::Product(U32 type) 
{
	return entry.Product( type );
}

bool atom::CInstanceFactory::Destroy(U64 instance) 
{
	return entry.Destroy( instance );
}

atom::CObjectPtr atom::CInstanceFactory::Inquire(U64 instance) 
{
	return entry.Inquire( instance );
}

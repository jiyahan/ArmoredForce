#include "CInstanceLife.h"
#include "../../maintainer/CMaintainer.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLife::CInstanceLife() 
{
	controller.SetNest( this );
	maintainer.SetNest( this );
	reference .SetNest( this );
	life      .SetNest( this );
}

atom::CInstanceLife::~CInstanceLife() 
{
}

bool atom::CInstanceLife::Initiate() 
{
	return life.Initiate();
}

bool atom::CInstanceLife::Shutdown() 
{
	return life.Shutdown();
}

void atom::CInstanceLife::SetName(U64 name) 
{
	UNREFERENCED_PARAMETER( name );
}

U64 atom::CInstanceLife::GetName() 
{
	return OID_INSTANCE_LIFE;
}

void atom::CInstanceLife::SetType(U32 type) 
{
	UNREFERENCED_PARAMETER( type );
}

U32 atom::CInstanceLife::GetType() 
{
	return OID_INSTANCE_LIFE;
}

const char * atom::CInstanceLife::ToString() 
{
	static char name[] = "Instance Life";
    return name;
}

int atom::CInstanceLife::IncRef() 
{
	return counter.Increase();
}

int atom::CInstanceLife::DecRef() 
{
	return counter.Decrease();
}

int atom::CInstanceLife::GetRef() 
{
	return counter.GetReference();
}

atom::IInterface * atom::CInstanceLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_INSTANCE_LIFE_CONTROLLER:
		if( controller.IncRef() )
			result = & controller;
        break;
	case IID_INSTANCE_LIFE_REFERENCE:
	case IID_INSTANCE_LIFE_NOTIFY:
		if( reference .IncRef() )
			result = & reference;
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

U64 atom::CInstanceLife::Create(U32 type) 
{
	return controller.Create( type );
}

int atom::CInstanceLife::Increase(U64 instance) 
{
	return reference.Increase( instance );
}

int atom::CInstanceLife::Decrease(U64 instance) 
{
	return reference.Decrease( instance );
}

int atom::CInstanceLife::GetReference(U64 instance) 
{
	return reference.GetReference( instance );
}

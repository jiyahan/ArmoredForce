#include "CReferencedObject.h"


atom::CReferencedObject::CReferencedObject() : 
type(0),name(0)
{
}

atom::CReferencedObject::~CReferencedObject() 
{
}

void atom::CReferencedObject::SetName(U64 value) 
{
    name = value;
}

U64 atom::CReferencedObject::GetName() 
{
	return name;
}

void atom::CReferencedObject::SetType(U32 value) 
{
    type = value;
}

U32 atom::CReferencedObject::GetType() 
{
	return type;
}

int atom::CReferencedObject::IncRef() 
{
	return lock.Increase();
}

int atom::CReferencedObject::DecRef() 
{
	return lock.Decrease();
}

int atom::CReferencedObject::GetRef() 
{
	return lock.GetReference();
}

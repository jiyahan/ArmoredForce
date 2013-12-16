#include "CAtomAllocator.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
//Begin section for file CAtomAllocator.cpp
//TODO: Add definitions that you want preserved
//End section for file CAtomAllocator.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAtomAllocator::CAtomAllocator() 
{
    //TODO Auto-generated method stub
	allocator.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAtomAllocator::~CAtomAllocator() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAtomAllocator::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CAtomAllocator::GetName() 
{
    //TODO Auto-generated method stub
	return OID_ATOM_ALLOCATOR;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAtomAllocator::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CAtomAllocator::GetType() 
{
    //TODO Auto-generated method stub
	return OID_ATOM_ALLOCATOR;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CAtomAllocator::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Atom Allocator";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CAtomAllocator::IncRef() 
{
    //TODO Auto-generated method stub
	return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CAtomAllocator::DecRef() 
{
    //TODO Auto-generated method stub
	return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CAtomAllocator::GetRef() 
{
    //TODO Auto-generated method stub
	return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CAtomAllocator::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

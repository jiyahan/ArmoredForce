#include "CElectronAllocator.h"
#include "../enumeration/SINGLETON_OBJECT_ID.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CElectronAllocator.cpp
//TODO: Add definitions that you want preserved
//End section for file CElectronAllocator.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CElectronAllocator::CElectronAllocator() 
{
    //TODO Auto-generated method stub
	allocator.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CElectronAllocator::~CElectronAllocator() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectronAllocator::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CElectronAllocator::GetName() 
{
    //TODO Auto-generated method stub
    return OID_ELECTRON_ALLOCATOR;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectronAllocator::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CElectronAllocator::GetType() 
{
    //TODO Auto-generated method stub
    return OID_ELECTRON_ALLOCATOR;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * electron::CElectronAllocator::ToString() 
{
    //TODO Auto-generated method stub
    static char name[] = "Electron Allocator";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CElectronAllocator::IncRef() 
{
    //TODO Auto-generated method stub
    return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CElectronAllocator::DecRef() 
{
    //TODO Auto-generated method stub
    return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CElectronAllocator::GetRef() 
{
    //TODO Auto-generated method stub
    return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CElectronAllocator::QueryInterface(U32 iid) 
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

#include "CInstanceFactory.h"
#include "../../maintainer/CMaintainer.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceFactory.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactory.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactory::CInstanceFactory() 
{
    //TODO Auto-generated method stub
	allocator .SetNest( this );
	entry     .SetNest( this );
	maintainer.SetNest( this );
	life      .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceFactory::~CInstanceFactory() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactory::Initiate() 
{
    //TODO Auto-generated method stub
	return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactory::Shutdown() 
{
    //TODO Auto-generated method stub
	return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceFactory::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceFactory::GetName() 
{
    //TODO Auto-generated method stub
	// keep reserved object's type and name are the same;
	return OID_INSTANCE_FACTORY;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceFactory::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CInstanceFactory::GetType() 
{
    //TODO Auto-generated method stub
	// keep reserved object's type and name are the same;
	return OID_INSTANCE_FACTORY;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CInstanceFactory::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Instance Factory";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactory::IncRef() 
{
    //TODO Auto-generated method stub
	return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactory::DecRef() 
{
    //TODO Auto-generated method stub
	return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceFactory::GetRef() 
{
    //TODO Auto-generated method stub
	return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CInstanceFactory::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactory::Attach(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
	return allocator.Attach( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactory::Detach(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
	return allocator.Detach( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceFactory::Product(U32 type) 
{
    //TODO Auto-generated method stub
	return entry.Product( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceFactory::Destroy(U64 instance) 
{
    //TODO Auto-generated method stub
	return entry.Destroy( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceFactory::Inquire(U64 instance) 
{
    //TODO Auto-generated method stub
	return entry.Inquire( instance );
}

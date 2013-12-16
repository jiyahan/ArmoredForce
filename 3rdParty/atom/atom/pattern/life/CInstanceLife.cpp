#include "CInstanceLife.h"
#include "../../maintainer/CMaintainer.h"
#include "../../enumeration/SINGLETON_OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLife::CInstanceLife() 
{
    //TODO Auto-generated method stub
	controller.SetNest( this );
	maintainer.SetNest( this );
	reference .SetNest( this );
	life      .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLife::~CInstanceLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLife::Initiate() 
{
    //TODO Auto-generated method stub
	return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLife::Shutdown() 
{
    //TODO Auto-generated method stub
	return life.Shutdown();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLife::SetName(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceLife::GetName() 
{
    //TODO Auto-generated method stub
	return OID_INSTANCE_LIFE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLife::SetType(U32 type) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CInstanceLife::GetType() 
{
    //TODO Auto-generated method stub
	return OID_INSTANCE_LIFE;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CInstanceLife::ToString() 
{
    //TODO Auto-generated method stub
	static char name[] = "Instance Life";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::IncRef() 
{
    //TODO Auto-generated method stub
	return counter.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::DecRef() 
{
    //TODO Auto-generated method stub
	return counter.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::GetRef() 
{
    //TODO Auto-generated method stub
	return counter.GetReference();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CInstanceLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceLife::Create(U32 type) 
{
    //TODO Auto-generated method stub
	return controller.Create( type );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::Increase(U64 instance) 
{
    //TODO Auto-generated method stub
	return reference.Increase( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::Decrease(U64 instance) 
{
    //TODO Auto-generated method stub
	return reference.Decrease( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLife::GetReference(U64 instance) 
{
    //TODO Auto-generated method stub
	return reference.GetReference( instance );
}

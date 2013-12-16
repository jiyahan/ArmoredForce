#include "CReferencedObject.h"
//Begin section for file CReferencedObject.cpp
//TODO: Add definitions that you want preserved
//End section for file CReferencedObject.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CReferencedObject::CReferencedObject() : 
type(0),name(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CReferencedObject::~CReferencedObject() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CReferencedObject::SetName(U64 value) 
{
    //TODO Auto-generated method stub
    name = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CReferencedObject::GetName() 
{
    //TODO Auto-generated method stub
	return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CReferencedObject::SetType(U32 value) 
{
    //TODO Auto-generated method stub
    type = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CReferencedObject::GetType() 
{
    //TODO Auto-generated method stub
	return type;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CReferencedObject::IncRef() 
{
    //TODO Auto-generated method stub
	return lock.Increase();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CReferencedObject::DecRef() 
{
    //TODO Auto-generated method stub
	return lock.Decrease();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CReferencedObject::GetRef() 
{
    //TODO Auto-generated method stub
	return lock.GetReference();
}

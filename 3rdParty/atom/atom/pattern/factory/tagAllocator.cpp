#include "tagAllocator.h"
//Begin section for file tagAllocator.cpp
//TODO: Add definitions that you want preserved
//End section for file tagAllocator.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagAllocator::tagAllocator() : 
lower(0),upper(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagAllocator::~tagAllocator() 
{
    //TODO Auto-generated method stub
	Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagAllocator::Clear() 
{
    //TODO Auto-generated method stub
    lower = 0;
	upper = 0;
	point = NULL;
}

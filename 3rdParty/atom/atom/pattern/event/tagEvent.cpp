#include "tagEvent.h"
//Begin section for file tagEvent.cpp
//TODO: Add definitions that you want preserved
//End section for file tagEvent.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagEvent::tagEvent() : 
handle(0),source(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagEvent::tagEvent(const tagEvent & value)
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagEvent::~tagEvent() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagEvent & atom::tagEvent::operator=(const tagEvent & value) 
{
    //TODO Auto-generated method stub
	handle = value.handle;
	append = value.append;
	source = value.source;
	target = value.target;
	record = value.record;
	return( *this );
}

#include "tagDomain.h"
//Begin section for file tagDomain.cpp
//TODO: Add definitions that you want preserved
//End section for file tagDomain.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagDomain::tagDomain() : 
port(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagDomain::tagDomain(const tagDomain & value) 
{
    //TODO Auto-generated method stub
	* this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagDomain::~tagDomain() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagDomain & atom::tagDomain::operator=(const tagDomain & value) 
{
    //TODO Auto-generated method stub
	host = value.host;
	port = value.port;
	return( * this );
}

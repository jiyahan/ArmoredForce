#include "tagTcpSelectOperation.h"
//Begin section for file tagTcpSelectOperation.cpp
//TODO: Add definitions that you want preserved
//End section for file tagTcpSelectOperation.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpSelectOperation::tagTcpSelectOperation() : 
socket(INVALID_SOCKET),offset(0),length(0),target(0),serial(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpSelectOperation::tagTcpSelectOperation(const tagTcpSelectOperation & value)
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpSelectOperation::~tagTcpSelectOperation() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpSelectOperation & atom::tagTcpSelectOperation::operator=(const tagTcpSelectOperation & value) 
{
    //TODO Auto-generated method stub
	socket = value.socket;
	memory = value.memory;
	offset = value.offset;
	length = value.length;
	target = value.target;
	serial = value.serial;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::tagTcpSelectOperation::operator<(const tagTcpSelectOperation & value) const 
{
    //TODO Auto-generated method stub
	return serial < value.serial;
}

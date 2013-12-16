#include "tagTcpKQueueOperation.h"
//Begin section for file tagTcpKQueueOperation.cpp
//TODO: Add definitions that you want preserved
//End section for file tagTcpKQueueOperation.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpKQueueOperation::tagTcpKQueueOperation() : 
offset(0),length(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagTcpKQueueOperation::~tagTcpKQueueOperation() 
{
    //TODO Auto-generated method stub
	Reset();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagTcpKQueueOperation::Reset() 
{
    //TODO Auto-generated method stub
    object = NULL;
	offset = 0;
	length = 0;
	memory.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagTcpKQueueOperation::Attach(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    object = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagTcpKQueueOperation::Detach() 
{
    //TODO Auto-generated method stub
    object = NULL;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::tagTcpKQueueOperation::Object() 
{
    //TODO Auto-generated method stub
	return object;
}

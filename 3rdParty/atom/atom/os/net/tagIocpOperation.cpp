#include "tagIocpOperation.h"
//Begin section for file tagIocpOperation.cpp
//TODO: Add definitions that you want preserved
//End section for file tagIocpOperation.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagIocpOperation::tagIocpOperation() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	op = 0;
	hs = INVALID_SOCKET;
	
	ZeroMemory( & ol, sizeof(CIocpOverlap) );
	ZeroMemory( & wb, sizeof(CIocpBuffer)  );
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagIocpOperation::~tagIocpOperation() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagIocpOperation::Reset() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	op = 0;
	hs = INVALID_SOCKET;

	ZeroMemory( & ol, sizeof(CIocpOverlap) );
	ZeroMemory( & wb, sizeof(CIocpBuffer)  );

	mb.Clear(); Detach();
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::tagIocpOperation::Attach(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	ob = object;
    return true;
	#else
	UNREFERENCED_PARAMETER( object );
	return false;
	#endif

}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagIocpOperation::Detach() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
    ob = NULL;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::tagIocpOperation::GetObjectName() 
{
    //TODO Auto-generated method stub
	U64 name = 0;
	#ifdef _WIN32
	if( ob ) name = ob -> GetName();
	#endif
	return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::tagIocpOperation::GetObject() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	return ob;
	#else
	return CObjectPtr();
	#endif
}

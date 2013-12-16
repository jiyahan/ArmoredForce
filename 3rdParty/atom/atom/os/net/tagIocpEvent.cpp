#include "tagIocpEvent.h"
//Begin section for file tagIocpEvent.cpp
//TODO: Add definitions that you want preserved
//End section for file tagIocpEvent.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagIocpEvent::tagIocpEvent() 
#ifdef _WIN32
: object(0),length(0),losted(false),packet(NULL)
#endif
{
    //TODO Auto-generated method stub
}
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagIocpEvent::Reset() 
{
    //TODO Auto-generated method stub
	#ifdef _WIN32
	object = 0;
	length = 0;
	losted = false;
	packet = NULL;
	#endif
}

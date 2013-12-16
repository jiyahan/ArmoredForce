#include "CMaintainer.h"
#include "../enumeration/THREAD_PRIORITY.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CMaintainer.cpp
//TODO: Add definitions that you want preserved
//End section for file CMaintainer.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainer::CMaintainer() 
{
    //TODO Auto-generated method stub
    thread   .SetNest( this );
    container.SetNest( this );
    listener .SetNest( this );
    timeline .SetNest( this );
	life     .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMaintainer::~CMaintainer() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CMaintainer::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_INSTANCE_CONTAINER:
        result = & container;
        break;
    case IID_INSTANCE_CONTAINER_LISTENER:
        result = & listener;
        break;
    case IID_MAINTAINER_TIMELINE:
        result = & timeline;
        break;
	case IID_INSTANCE_LIFE:
		result = & life;
		break;
	case IID_THREAD_CONTROL:
		result = & thread;
		break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainer::Attach(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    return container.Insert( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainer::Detach(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
	if( value ) {
		container.Remove( value -> GetName() );
	} 
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMaintainer::Detach(U64 name) 
{
    //TODO Auto-generated method stub
    container.Remove( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainer::Initiate() 
{
    //TODO Auto-generated method stub
	return life.Initiate();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMaintainer::Shutdown() 
{
    //TODO Auto-generated method stub
	return life.Shutdown();
}

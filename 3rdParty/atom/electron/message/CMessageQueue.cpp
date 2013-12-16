#include "CMessageQueue.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CMessageQueue.cpp
//TODO: Add definitions that you want preserved
//End section for file CMessageQueue.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueue::CMessageQueue() 
{
    //TODO Auto-generated method stub
    controller.SetNest( this );
    life      .SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueue::~CMessageQueue() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * electron::CMessageQueue::ToString() 
{
    //TODO Auto-generated method stub
    static char name[] = "Message Queue";
    return name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CMessageQueue::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_INSTANCE_LIFE:
        if( life      .IncRef() ) {
            result = & life;
        }
        break;
    case IID_MESSAGE_QUEUE_CONTROLLER:
        if( controller.IncRef() ) {
            result = & controller;
        }
        break;
    }
    return result;
}

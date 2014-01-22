#include "CMessageQueue.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CMessageQueue::CMessageQueue() 
{
    controller.SetNest( this );
    life      .SetNest( this );
}

electron::CMessageQueue::~CMessageQueue() 
{
}

const char * electron::CMessageQueue::ToString() 
{
    static char name[] = "Message Queue";
    return name;
}

IInterface * electron::CMessageQueue::QueryInterface(U32 iid) 
{
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

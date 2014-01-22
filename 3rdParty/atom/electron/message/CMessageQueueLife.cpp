#include "CMessageQueueLife.h"
#include "../interface/IMessageQueueController.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CMessageQueueLife::CMessageQueueLife() : 
nest(NULL)
{
}

electron::CMessageQueueLife::~CMessageQueueLife() 
{
}

int electron::CMessageQueueLife::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int electron::CMessageQueueLife::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int electron::CMessageQueueLife::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

IInterface * electron::CMessageQueueLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CMessageQueueLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool electron::CMessageQueueLife::Initiate() 
{
    return true;
}

bool electron::CMessageQueueLife::Shutdown() 
{
    CInterface<IMessageQueueController> segment;
    if( segment.Mount(this, IID_MESSAGE_QUEUE_CONTROLLER) ) {
        segment -> Clear();
    }
    return true;
}

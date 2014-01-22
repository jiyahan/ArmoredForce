#include "CMessageQueueController.h"


electron::CMessageQueueController::CMessageQueueController() : 
nest(NULL),amount(1)
{
}

electron::CMessageQueueController::~CMessageQueueController() 
{
}

int electron::CMessageQueueController::IncRef() 
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

int electron::CMessageQueueController::DecRef() 
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

int electron::CMessageQueueController::GetRef() 
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

IInterface * electron::CMessageQueueController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CMessageQueueController::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

void electron::CMessageQueueController::Clear() 
{
    return;
}

void electron::CMessageQueueController::SetQueueAmount(U32 length) 
{
    if( length ) {
        amount = atom_min( length, MAX_MESSAGE_QUEUE_CONTROLLER_SET );
        amount = atom_max( amount, 1 );
    }
}

U32 electron::CMessageQueueController::GetQueueAmount() 
{
    return amount;
}

bool electron::CMessageQueueController::Insert(U64 id, CMessage * message) 
{
	bool result = false;
    if( message && amount ) 
    {
        result = 
        queues[id % amount].Insert( message );
		signal[id % amount].Awake(); 
	}
	return result;
}

bool electron::CMessageQueueController::Obtain(U32 id, CMessageQueueControllerSetBind & out) 
{
    bool result = false;
    if( id < amount ) {
        result = queues[id].Obtain( out ); 
	}
	return result;
}

void electron::CMessageQueueController::Repose(U32 id, U64 timeout) 
{
    if( id < amount ) {
        signal[id].Await( timeout );
		signal[id].Reset();
    }
}

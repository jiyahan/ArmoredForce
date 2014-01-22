#include "CInstanceLifeReference.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/math/random/CRandom.h"
#include "../../interface/IInstanceLifeController.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLifeReference::CInstanceLifeReference() : 
nest(NULL)
{
}

atom::CInstanceLifeReference::~CInstanceLifeReference() 
{
}

int atom::CInstanceLifeReference::IncRef() 
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

int atom::CInstanceLifeReference::DecRef() 
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

int atom::CInstanceLifeReference::GetRef() 
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
    return result;}

atom::IInterface * atom::CInstanceLifeReference::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceLifeReference::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CInstanceLifeReference::Insert(U64 instance) 
{
    return references.Insert( instance, receiver );
}

bool atom::CInstanceLifeReference::Remove(U64 instance) 
{
    return references.Remove( instance, receiver );
}

int atom::CInstanceLifeReference::Increase(U64 instance) 
{
    return references.Increase( instance );
}

int atom::CInstanceLifeReference::Decrease(U64 instance) 
{
    int result = references.Decrease( instance );
    if( 0 == result )
    {
        CInterface<IInstanceLifeController> segment;
        if( segment.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
            segment -> Remove( instance, 5000 + CRandom::Random() % 5000 );
    	}
    }
    return result;
}

int atom::CInstanceLifeReference::GetReference(U64 instance) 
{
    return references.GetReference( instance );
}

void atom::CInstanceLifeReference::GetInstances(CU64Array & instances) 
{
    references.GetInstances( instances );
}

void atom::CInstanceLifeReference::SetReceiver(CObjectPtr & value) 
{
    receiver = value;
}

atom::CObjectPtr atom::CInstanceLifeReference::GetReceiver() 
{
    return receiver;
}

bool atom::CInstanceLifeReference::Initiate() 
{
	return true;
}

bool atom::CInstanceLifeReference::Shutdown() 
{
	references.Clear( receiver ); receiver = NULL;
	return true;
}

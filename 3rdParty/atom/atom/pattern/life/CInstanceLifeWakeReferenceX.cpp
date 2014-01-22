#include "CInstanceLifeWakeReferenceX.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLifeWakeReferenceX::CInstanceLifeWakeReferenceX() 
{
}

atom::CInstanceLifeWakeReferenceX::~CInstanceLifeWakeReferenceX() 
{
}

bool atom::CInstanceLifeWakeReferenceX::Insert(U64 instance, CObjectPtr & receiver) 
{
    bool result = false;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Insert( instance, receiver );
	}
    return result;
}

bool atom::CInstanceLifeWakeReferenceX::Remove(U64 instance, CObjectPtr & receiver) 
{
    bool result = false;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Remove( instance, receiver );
	}
    return result;
}

int atom::CInstanceLifeWakeReferenceX::Increase(U64 instance) 
{
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Increase( instance );
	}
    return result;
}

int atom::CInstanceLifeWakeReferenceX::Decrease(U64 instance) 
{
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Decrease( instance );
	}
    return result;
}

void atom::CInstanceLifeWakeReferenceX::Clear(CObjectPtr & receiver) 
{
	CU64Array indices;
	GetInstances( indices );

	//clear all containers
	for( size_t i = 0, j = indices.size(); i < j; ++ i )
	{
		CObjectPtr object =
			CInstanceFactory::GetInstance() -> Inquire( indices[i] );
		if( object )
		{
			CInterface<IInstanceContainer> segment;
			if( segment.Mount(object, IID_INSTANCE_CONTAINER) ) {
				segment -> RemoveAll();
			}
		}
	}

	// remove all reference;
    for( size_t i = 0; i < INSTANCES_QUEUE; ++ i )
    {
        instances[i].Clear( receiver );
    }
}

int atom::CInstanceLifeWakeReferenceX::GetReference(U64 instance) 
{
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].GetReference( instance );
	}
    return result;
}

void atom::CInstanceLifeWakeReferenceX::GetInstances(CU64Array & indices) 
{
    for( size_t i = 0; i < INSTANCES_QUEUE; ++ i )
    {
        instances[i].GetInstances( indices );
    }
}

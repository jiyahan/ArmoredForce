#include "CInstanceLifeRemoveQueue.h"


atom::CInstanceLifeRemoveQueue::CInstanceLifeRemoveQueue() 
{
}

atom::CInstanceLifeRemoveQueue::~CInstanceLifeRemoveQueue() 
{
}

void atom::CInstanceLifeRemoveQueue::Clear() 
{
	CU64Array out;
	for( size_t i = 0; i < LIFE_REMOVE_QUEUE; ++ i ) {
		queues[i].Forward( U64(INFINITE), out );
	}
}

void atom::CInstanceLifeRemoveQueue::Insert(U64 time, U64 instance) 
{
	size_t offset = static_cast<size_t>( instance % LIFE_REMOVE_QUEUE );
	queues[offset].Mark( time, instance );
}

void atom::CInstanceLifeRemoveQueue::Obtain(U64 time, CU64Array & instances) 
{
    for( size_t i = 0; i < LIFE_REMOVE_QUEUE; ++ i ) {
        queues[i].Forward( time, instances ); 
    }
}

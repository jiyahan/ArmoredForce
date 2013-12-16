#include "CInstanceLifeRemoveQueue.h"
//Begin section for file CInstanceLifeRemoveQueue.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeRemoveQueue.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeRemoveQueue::CInstanceLifeRemoveQueue() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeRemoveQueue::~CInstanceLifeRemoveQueue() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeRemoveQueue::Clear() 
{
    //TODO Auto-generated method stub
	CU64Array out;
	for( size_t i = 0; i < LIFE_REMOVE_QUEUE; ++ i ) {
		queues[i].Forward( U64(INFINITE), out );
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeRemoveQueue::Insert(U64 time, U64 instance) 
{
    //TODO Auto-generated method stub
	size_t offset = static_cast<size_t>( instance % LIFE_REMOVE_QUEUE );
	queues[offset].Mark( time, instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeRemoveQueue::Obtain(U64 time, CU64Array & instances) 
{
    //TODO Auto-generated method stub
    for( size_t i = 0; i < LIFE_REMOVE_QUEUE; ++ i ) {
        queues[i].Forward( time, instances ); 
    }
}

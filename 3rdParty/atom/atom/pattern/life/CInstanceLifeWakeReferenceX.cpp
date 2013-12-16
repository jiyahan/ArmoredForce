#include "CInstanceLifeWakeReferenceX.h"
#include "../factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceLifeWakeReferenceX.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeWakeReferenceX.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeWakeReferenceX::CInstanceLifeWakeReferenceX() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeWakeReferenceX::~CInstanceLifeWakeReferenceX() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeWakeReferenceX::Insert(U64 instance, CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
    bool result = false;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Insert( instance, receiver );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeWakeReferenceX::Remove(U64 instance, CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
    bool result = false;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Remove( instance, receiver );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReferenceX::Increase(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Increase( instance );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReferenceX::Decrease(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].Decrease( instance );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeWakeReferenceX::Clear(CObjectPtr & receiver) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeWakeReferenceX::GetReference(U64 instance) 
{
    //TODO Auto-generated method stub
    int result = 0;
	if( instance )
	{
        size_t offset = static_cast<size_t>( instance % INSTANCES_QUEUE );
        result = instances[offset].GetReference( instance );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeWakeReferenceX::GetInstances(CU64Array & indices) 
{
    //TODO Auto-generated method stub
    for( size_t i = 0; i < INSTANCES_QUEUE; ++ i )
    {
        instances[i].GetInstances( indices );
    }
}

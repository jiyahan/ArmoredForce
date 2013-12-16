#include "CMessageQueueController.h"
//Begin section for file CMessageQueueController.cpp
//TODO: Add definitions that you want preserved
//End section for file CMessageQueueController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueueController::CMessageQueueController() : 
nest(NULL),amount(1)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueueController::~CMessageQueueController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CMessageQueueController::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CMessageQueueController::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CMessageQueueController::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CMessageQueueController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessageQueueController::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessageQueueController::Clear() 
{
    //TODO Auto-generated method stub
    return;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessageQueueController::SetQueueAmount(U32 length) 
{
    //TODO Auto-generated method stub
    if( length ) {
        amount = atom_min( length, MAX_MESSAGE_QUEUE_CONTROLLER_SET );
        amount = atom_max( amount, 1 );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CMessageQueueController::GetQueueAmount() 
{
    //TODO Auto-generated method stub
    return amount;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessageQueueController::Insert(U64 id, CMessage * message) 
{
    //TODO Auto-generated method stub
	bool result = false;
    if( message && amount ) 
    {
        result = 
        queues[id % amount].Insert( message );
		signal[id % amount].Awake(); 
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessageQueueController::Obtain(U32 id, CMessageQueueControllerSetBind & out) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( id < amount ) {
        result = queues[id].Obtain( out ); 
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CMessageQueueController::Repose(U32 id, U64 timeout) 
{
    //TODO Auto-generated method stub
    if( id < amount ) {
        signal[id].Await( timeout );
		signal[id].Reset();
    }
}

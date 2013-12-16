#include "CInstanceLifeReference.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/math/random/CRandom.h"
#include "../../interface/IInstanceLifeController.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CInstanceLifeReference.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeReference.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeReference::CInstanceLifeReference() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceLifeReference::~CInstanceLifeReference() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeReference::IncRef() 
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
int atom::CInstanceLifeReference::DecRef() 
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
int atom::CInstanceLifeReference::GetRef() 
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
    return result;}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CInstanceLifeReference::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeReference::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeReference::Insert(U64 instance) 
{
    //TODO Auto-generated method stub
    return references.Insert( instance, receiver );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeReference::Remove(U64 instance) 
{
    //TODO Auto-generated method stub
    return references.Remove( instance, receiver );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeReference::Increase(U64 instance) 
{
    //TODO Auto-generated method stub
    return references.Increase( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeReference::Decrease(U64 instance) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CInstanceLifeReference::GetReference(U64 instance) 
{
    //TODO Auto-generated method stub
    return references.GetReference( instance );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeReference::GetInstances(CU64Array & instances) 
{
    //TODO Auto-generated method stub
    references.GetInstances( instances );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceLifeReference::SetReceiver(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    receiver = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceLifeReference::GetReceiver() 
{
    //TODO Auto-generated method stub
    return receiver;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeReference::Initiate() 
{
    //TODO Auto-generated method stub
	return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceLifeReference::Shutdown() 
{
    //TODO Auto-generated method stub
	references.Clear( receiver ); receiver = NULL;
	return true;
}

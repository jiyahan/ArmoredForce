#include "CElectronInstanceAllocator.h"
#include "../enumeration/OBJECT_ID.h"
#include "../message/CMessageQueue.h"
#include "../stub/CConnectorStub.h"
//Begin section for file CElectronInstanceAllocator.cpp
//TODO: Add definitions that you want preserved
//End section for file CElectronInstanceAllocator.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CElectronInstanceAllocator::CElectronInstanceAllocator() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CElectronInstanceAllocator::~CElectronInstanceAllocator() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CElectronInstanceAllocator::IncRef() 
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
int electron::CElectronInstanceAllocator::DecRef() 
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
int electron::CElectronInstanceAllocator::GetRef() 
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
IInterface * electron::CElectronInstanceAllocator::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectronInstanceAllocator::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
CReferencedObject * electron::CElectronInstanceAllocator::Product(U32 type) 
{
    //TODO Auto-generated method stub
	CReferencedObject * result = NULL;
	if( type )
	{
		switch( type )
		{
        case OID_MESSAGE_QUEUE:
            result = new CMessageQueue;
			break;
        case OID_CONNECTOR_STUB:
            result = new CConnectorStub;
			break;
		default:
			break;
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectronInstanceAllocator::Destroy(CReferencedObject * value) 
{
    //TODO Auto-generated method stub
	SAFE_DELETE( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectronInstanceAllocator::Confine(U32 & lower, U32 & upper) 
{
    //TODO Auto-generated method stub
	lower = OID_MESSAGE_QUEUE;
	upper = OID_CONNECTOR_STUB;
}

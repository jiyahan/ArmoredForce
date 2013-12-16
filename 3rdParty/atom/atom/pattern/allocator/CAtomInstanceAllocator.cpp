#include "CAtomInstanceAllocator.h"
#include "../event/CEventSpace.h"
#include "../../os/net/CTcpConnector.h"
#include "../../os/net/CTcpListener.h"
#include "../../os/net/CTcpSelectModel.h"
#include "../../os/net/CTcpIocpModel.h"
#include "../../os/net/CTcpKQueueModel.h"
#include "../../os/net/CTcpEpollModel.h"
#include "../../utility/xml/CXmlDocument.h"
#include "../../utility/xml/CXmlElement.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CAtomInstanceAllocator.cpp
//TODO: Add definitions that you want preserved
//End section for file CAtomInstanceAllocator.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAtomInstanceAllocator::CAtomInstanceAllocator() : 
nest(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAtomInstanceAllocator::~CAtomInstanceAllocator() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CAtomInstanceAllocator::IncRef() 
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
int atom::CAtomInstanceAllocator::DecRef() 
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
int atom::CAtomInstanceAllocator::GetRef() 
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
atom::IInterface * atom::CAtomInstanceAllocator::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAtomInstanceAllocator::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CReferencedObject * atom::CAtomInstanceAllocator::Product(U32 type) 
{
    //TODO Auto-generated method stub
	CReferencedObject * result = NULL;
	if( type )
	{
		switch( type )
		{
		case OID_EVENT_SPACE:
			result = new CEventSpace;
			break;
		case OID_TCP_CONNECTOR:
			result = new CTcpConnector;
			break;
		case OID_TCP_LISTENER:
			result = new CTcpListener;
			break;
		case OID_TCP_SELECT_MODEL:
			result = new CTcpSelectModel;
			break;
		case OID_TCP_IOCP_MODEL:
			result = new CTcpIocpModel;
			break;
		case OID_TCP_KQUEUE_MODEL:
			result = new CTcpKQueueModel;
			break;
		case OID_TCP_EPOLL_MODEL:
			result = new CTcpEpollModel;
			break;
		case OID_XML_ELEMENT:
			result = new CXmlElement;
			break;
		case OID_XML_DOCUMENT:
			result = new CXmlDocument;
			break;
		default:
			break;
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAtomInstanceAllocator::Destroy(CReferencedObject * value) 
{
    //TODO Auto-generated method stub
	SAFE_DELETE( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAtomInstanceAllocator::Confine(U32 & lower, U32 & upper) 
{
    //TODO Auto-generated method stub
	lower = OID_EVENT_SPACE;
	upper = OID_ATOM_END;
}

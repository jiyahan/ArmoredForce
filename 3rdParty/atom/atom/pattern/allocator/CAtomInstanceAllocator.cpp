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


atom::CAtomInstanceAllocator::CAtomInstanceAllocator() : 
nest(NULL)
{
}

atom::CAtomInstanceAllocator::~CAtomInstanceAllocator() 
{
}

int atom::CAtomInstanceAllocator::IncRef() 
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

int atom::CAtomInstanceAllocator::DecRef() 
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

int atom::CAtomInstanceAllocator::GetRef() 
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

atom::IInterface * atom::CAtomInstanceAllocator::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CAtomInstanceAllocator::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

atom::CReferencedObject * atom::CAtomInstanceAllocator::Product(U32 type) 
{
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

void atom::CAtomInstanceAllocator::Destroy(CReferencedObject * value) 
{
	SAFE_DELETE( value );
}

void atom::CAtomInstanceAllocator::Confine(U32 & lower, U32 & upper) 
{
	lower = OID_EVENT_SPACE;
	upper = OID_ATOM_END;
}

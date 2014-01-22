#include "CElectronInstanceAllocator.h"
#include "../enumeration/OBJECT_ID.h"
#include "../message/CMessageQueue.h"
#include "../stub/CConnectorStub.h"


electron::CElectronInstanceAllocator::CElectronInstanceAllocator() : 
nest(NULL)
{
}

electron::CElectronInstanceAllocator::~CElectronInstanceAllocator() 
{
}

int electron::CElectronInstanceAllocator::IncRef() 
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

int electron::CElectronInstanceAllocator::DecRef() 
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

int electron::CElectronInstanceAllocator::GetRef() 
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

IInterface * electron::CElectronInstanceAllocator::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CElectronInstanceAllocator::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

CReferencedObject * electron::CElectronInstanceAllocator::Product(U32 type) 
{
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

void electron::CElectronInstanceAllocator::Destroy(CReferencedObject * value) 
{
	SAFE_DELETE( value );
}

void electron::CElectronInstanceAllocator::Confine(U32 & lower, U32 & upper) 
{
	lower = OID_MESSAGE_QUEUE;
	upper = OID_CONNECTOR_STUB;
}

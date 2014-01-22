#include "CInstanceFactoryLife.h"
#include "../../maintainer/CMaintainer.h"
#include "../../interface/IInstanceFactoryEntry.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"


atom::CInstanceFactoryLife::CInstanceFactoryLife() : 
nest(NULL)
{
}

atom::CInstanceFactoryLife::~CInstanceFactoryLife() 
{
}

int atom::CInstanceFactoryLife::IncRef() 
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

int atom::CInstanceFactoryLife::DecRef() 
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

int atom::CInstanceFactoryLife::GetRef() 
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

atom::IInterface * atom::CInstanceFactoryLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceFactoryLife::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CInstanceFactoryLife::Initiate() 
{
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }
    return true;
}

bool atom::CInstanceFactoryLife::Shutdown() 
{
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

	bool result = false;
	CInterface<IInstanceFactoryEntry> segment;
	if( segment.Mount(this, IID_INSTANCE_FACTORY_ENTRY) ) {
		result = segment -> Shutdown();
	}
	return result;
}

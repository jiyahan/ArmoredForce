#include "CInstanceLifeEntry.h"
#include "../../maintainer/CMaintainer.h"
#include "../../interface/IInstanceLifeController.h"
#include "../../interface/IInstanceLifeReference.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"


atom::CInstanceLifeEntry::CInstanceLifeEntry() : 
nest(NULL)
{
}

atom::CInstanceLifeEntry::~CInstanceLifeEntry() 
{
}

int atom::CInstanceLifeEntry::IncRef() 
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

int atom::CInstanceLifeEntry::DecRef() 
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

int atom::CInstanceLifeEntry::GetRef() 
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

atom::IInterface * atom::CInstanceLifeEntry::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceLifeEntry::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CInstanceLifeEntry::Initiate() 
{
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Attach( object );
    }

	bool result = true;
	CInterface<IInstanceLifeController> segment_1;
	if( segment_1.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
		result = segment_1 -> Initiate() && result;
	}

	CInterface<IInstanceLifeReference>  segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_LIFE_REFERENCE) ) {
		result = segment_2 -> Initiate() && result;
	}
    return result;
}

bool atom::CInstanceLifeEntry::Shutdown() 
{
	CObjectPtr object = 
        CInstanceUtility::MakeObject( nest );
    if( object ) {
	    CMaintainer::GetInstance() -> Detach( object );
    }

	bool result = true;
	CInterface<IInstanceLifeReference>  segment_2;
	if( segment_2.Mount(this, IID_INSTANCE_LIFE_REFERENCE) ) {
		result = segment_2 -> Shutdown() && result;
	}

	CInterface<IInstanceLifeController> segment_1;
	if( segment_1.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
		result = segment_1 -> Shutdown() && result;
	}
    return result;
}

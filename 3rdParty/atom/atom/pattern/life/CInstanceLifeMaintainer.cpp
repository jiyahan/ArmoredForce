#include "CInstanceLifeMaintainer.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceLifeController.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceLifeMaintainer::CInstanceLifeMaintainer() : 
nest(NULL)
{
}

atom::CInstanceLifeMaintainer::~CInstanceLifeMaintainer() 
{
}

int atom::CInstanceLifeMaintainer::IncRef() 
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

int atom::CInstanceLifeMaintainer::DecRef() 
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

int atom::CInstanceLifeMaintainer::GetRef() 
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

atom::IInterface * atom::CInstanceLifeMaintainer::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceLifeMaintainer::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

U64 atom::CInstanceLifeMaintainer::OnMaintenance(U64 now) 
{
	// visit this interface every 0.5 second;
	CInterface<IInstanceLifeController> segment;
	if( segment.Mount(this, IID_INSTANCE_LIFE_CONTROLLER) ) {
		segment -> OnProcess( now );
	}
	return now + 500;
}

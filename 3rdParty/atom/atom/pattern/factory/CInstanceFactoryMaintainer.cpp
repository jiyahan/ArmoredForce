#include "CInstanceFactoryMaintainer.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IInstanceFactoryEntry.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CInstanceFactoryMaintainer::CInstanceFactoryMaintainer() : 
nest(NULL)
{
}

atom::CInstanceFactoryMaintainer::~CInstanceFactoryMaintainer() 
{
}

int atom::CInstanceFactoryMaintainer::IncRef() 
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

int atom::CInstanceFactoryMaintainer::DecRef() 
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

int atom::CInstanceFactoryMaintainer::GetRef() 
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

atom::IInterface * atom::CInstanceFactoryMaintainer::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CInstanceFactoryMaintainer::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

U64 atom::CInstanceFactoryMaintainer::OnMaintenance(U64 now) 
{

	// call background object recycle;
	CInterface<IInstanceFactoryEntry> segment;
	if( segment.Mount(this, IID_INSTANCE_FACTORY_ENTRY) ) {
		segment -> Recycle();
	}

	// recall after 1 second;
	return now + 1000;
}

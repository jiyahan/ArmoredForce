#include "CEventServiceEntry.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"


atom::CEventServiceEntry::CEventServiceEntry() : 
nest(NULL)
{
}

atom::CEventServiceEntry::~CEventServiceEntry() 
{
}

int atom::CEventServiceEntry::IncRef() 
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

int atom::CEventServiceEntry::DecRef() 
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

int atom::CEventServiceEntry::GetRef() 
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

atom::IInterface * atom::CEventServiceEntry::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventServiceEntry::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

U64 atom::CEventServiceEntry::Create() 
{
	U64 result = 0;
	CObjectPtr instance = 
		CInstanceUtility::CreateInstance( OID_EVENT_SPACE );
	if( instance )
	{
		if( CInstanceUtility::InitiateInstance(instance) )
		{
			CInterface<IInstanceContainer> container;
			if( container.Mount(this, IID_INSTANCE_CONTAINER) )
			{
				if( container -> Insert(instance) ) {
					result = instance -> GetName();
				}
			}
		}
	}
	return result;
}

void atom::CEventServiceEntry::Remove(U64 space) 
{
	if( space )
	{
		CInterface<IInstanceContainer> container;
		if( container.Mount(this, IID_INSTANCE_CONTAINER) )
		{
			CObjectPtr instance = container -> Obtain( space );
			if( instance )
			{
				// remove space from container;
				container -> Remove( space );

				// before life service destroy instance, invoke shutdown
				// method, do final clear;
				CInterface<IInstanceLife> life;
				if( life.Mount(instance, IID_INSTANCE_LIFE) ) {
					life -> Shutdown();
				}
			}
		}
	}
}

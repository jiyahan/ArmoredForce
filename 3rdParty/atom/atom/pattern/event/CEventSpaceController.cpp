#include "CEventSpaceController.h"
#include "CEventService.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IEventReceiver.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CEventSpaceController::CEventSpaceController() : 
nest(NULL)
{
}

atom::CEventSpaceController::~CEventSpaceController() 
{
}

int atom::CEventSpaceController::IncRef() 
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

int atom::CEventSpaceController::DecRef() 
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

int atom::CEventSpaceController::GetRef() 
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

atom::IInterface * atom::CEventSpaceController::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventSpaceController::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CEventSpaceController::Initiate() 
{
    return true;
}

bool atom::CEventSpaceController::Shutdown() 
{
	queue_entry.Enter();
	queue.clear();
	queue_entry.Leave();

	alias_entry.Enter();
	alias.clear();
	alias_entry.Leave();

    return true;
}

bool atom::CEventSpaceController::Attach(CObjectPtr & receiver, const char * name) 
{
	bool result = false;
	if( receiver )
	{
		CInterface<IInstanceContainer> segment;
		if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
		{
			// first, insert receiver into container;
			result = segment -> Insert( receiver );

			// if succeeded, and receiver bind with a alias, try to insert into alias map;
			if( name && result )
			{
				CCriticalSectionScope scope( alias_entry );
				pair<CEventSpaceControllerAliasBind::iterator, 
					bool> retval = alias.insert( make_pair( name, receiver -> GetName() ) );
				if( retval.second == false )
				{
					result = false;
					segment -> Remove( receiver -> GetName() );
				}
			}
		}
	}
    return result;
}

void atom::CEventSpaceController::Detach(U64 receiver) 
{
	if( receiver )
	{
		CInterface<IInstanceContainer> segment;
		if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
			segment -> Remove( receiver );
		}

		CCriticalSectionScope scope( alias_entry );
		for( CEventSpaceControllerAliasBind::
			iterator it = alias.begin(); it != alias.end(); ++ it )
		{
			if( it -> second == receiver ) {
				alias.erase( it ); break;
			}
		}
	}
}

bool atom::CEventSpaceController::OnEvent(const tagEvent & value) 
{
	// handle and source must not be empty;
	bool result = value.handle && value.source && nest;

	// if ok, try to insert into event queue;
	if( result )
	{
		queue_entry.Enter();
		queue.push_back( value ); 
		queue_entry.Leave();

		// notify event service;
        CEventService::GetInstance() -> 
            Notify( CInstanceUtility::GetInstanceName(nest) );
	}
    return result;
}

void atom::CEventSpaceController::OnProcess() 
{
	CEventSpaceControllerQueueBind events;

	queue_entry.Enter();
	queue.swap( events );
	queue_entry.Leave();

	if( events.empty() ) return;
	CU64Array indices; indices.reserve( 64 );

	CInterface<IInstanceContainer> segment;
	if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
	{
		for( CEventSpaceControllerQueueBind::
			iterator it = events.begin(); it != events.end(); ++ it )
		{
			// clear indices and check target is empty, if target is empty, 
			// try to get all receiver from contianer;
			indices.clear();
			if( it -> target.empty() ) {
				segment -> Obtain( indices );
			}

			// if target is not empty, try to get receiver name from alias
			// map, if name is valid, insert into indices;
			else 
			{
				U64 name = GetTarget( it -> target );
				if( name ) indices.push_back( name );
			}

			// find all receivers inside indices, and query these receiver's 
			// instance, and report event;
			for( size_t i = 0, j = indices.size(); i < j; ++ i ) 
			{
				CObjectPtr instance = segment -> Obtain( indices[i] );
				SendEvent( instance, *it );
			}
		}
	}
}

U64 atom::CEventSpaceController::GetTarget(a_string & name)
{
	U64 result = 0;
	CCriticalSectionScope scope( alias_entry );
	CEventSpaceControllerAliasBind::
		iterator it = alias.find( name );
	if( it != alias.end() ) {
		result = it -> second;
	}
	return result;
}

void atom::CEventSpaceController::SendEvent(CObjectPtr & instance, tagEvent & value )
{
	if( instance != NULL )
	{
		CInterface<IEventReceiver> receiver;
		if( receiver.Mount(instance, IID_EVENT_RECEIVER) ) {
			receiver -> OnEvent( value );
		}
	}
}

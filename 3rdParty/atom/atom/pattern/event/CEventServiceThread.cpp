#include "CEventServiceThread.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IEventServiceTimeline.h"
#include "../../interface/IEventSpaceController.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CEventServiceThread::CEventServiceThread() : 
CThread("Event Service"),nest(NULL),active(false)
{
}

atom::CEventServiceThread::~CEventServiceThread() 
{
}

void atom::CEventServiceThread::SetActive(bool value) 
{
    active = value;
}

bool atom::CEventServiceThread::GetActive() 
{
    return active;
}

int atom::CEventServiceThread::IncRef() 
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

int atom::CEventServiceThread::DecRef() 
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

int atom::CEventServiceThread::GetRef() 
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

atom::IInterface * atom::CEventServiceThread::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CEventServiceThread::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CEventServiceThread::OnThreadBegin() 
{
    return true;
}

bool atom::CEventServiceThread::OnThreadClose() 
{
    return true;
}

U32 atom::CEventServiceThread::Run() 
{
	U32 result = 1;
	CInterface<IEventServiceTimeline> segment_1;
	CInterface<IInstanceContainer>    segment_2;

	if( segment_1.Mount(this, IID_EVENT_SERVICE_TIMELINE) &&
		segment_2.Mount(this, IID_INSTANCE_CONTAINER) )
	{
		result = 0;
		CU64Array indices;

		for( ;; )
		{
			indices.clear();
			segment_1 -> Forward( CMilisecondTimer::Now(), indices );

			for( size_t i = 0, j = indices.size(); i < j; ++ i )
			{
				CObjectPtr instance = segment_2 -> Obtain( indices[i] );
				if( instance )
				{
					CInterface<IEventSpaceController> controller;
					if( controller.Mount(instance, IID_EVENT_SPACE_CONTROLLER) ) {
						controller -> OnProcess();
					}
				}
			}

			if( !active ) break;

			// after waitting timeout, reset signal at once;
			signal.Await( 1000 );
			signal.Reset();
		}
	}
	return result;
}

bool atom::CEventServiceThread::OnBegin() 
{
    SetActive( true );
    return Begin( TP_BELOW_NORMAL );
}

bool atom::CEventServiceThread::OnClose() 
{
    SetActive( false );
	OnAwake();
    Close( U64(INFINITE) );
    return true;
}

void atom::CEventServiceThread::OnAwake() 
{
	signal.Awake();
}

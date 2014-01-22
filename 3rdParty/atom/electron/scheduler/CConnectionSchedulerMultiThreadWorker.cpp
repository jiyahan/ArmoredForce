#include "CConnectionSchedulerMultiThreadWorker.h"
#include "../interface/IConnectionSchedulerController.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CConnectionSchedulerMultiThreadWorker::CConnectionSchedulerMultiThreadWorker() : 
CThread("Connection scheduler worker"),serial(0),active(false)
{
}

electron::CConnectionSchedulerMultiThreadWorker::~CConnectionSchedulerMultiThreadWorker() 
{
}

U32 electron::CConnectionSchedulerMultiThreadWorker::Run() 
{
    U32 result(0);
    CObjectPtr nest = object;
    if( nest && serial < MAX_SCHEDULER_WORKER_THREAD )
    {
        CInterface<IConnectionSchedulerController> segment;
        if( segment.Mount(nest, IID_CONNECTION_SCHEDULER_CONTROLLER) )
        {
            for( ;; )
            {
                segment -> Retrieve( serial );
                if( !active ) break;

			    signal.Await( 1000 );
			    signal.Reset();
            }
        }
    }
    return result;
}

bool electron::CConnectionSchedulerMultiThreadWorker::OnThreadBegin() 
{
    return true;
}

bool electron::CConnectionSchedulerMultiThreadWorker::OnThreadClose() 
{
    return true;
}

void electron::CConnectionSchedulerMultiThreadWorker::SetObject(CObjectPtr & value) 
{
    object = value;
}

void electron::CConnectionSchedulerMultiThreadWorker::SetActive(bool value) 
{
    active = value;
}

void electron::CConnectionSchedulerMultiThreadWorker::SetAwaken() 
{
    signal.Awake();
}

void electron::CConnectionSchedulerMultiThreadWorker::SetSerial(U32 value) 
{
    serial = value;
}

bool electron::CConnectionSchedulerMultiThreadWorker::GetActive() 
{
    return active;
}

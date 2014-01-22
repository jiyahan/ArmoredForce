#include "CConnectionSchedulerMultiThread.h"


electron::CConnectionSchedulerMultiThread::CConnectionSchedulerMultiThread() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
amount(1)
{
    for( U32 i = 0; i < MAX_SCHEDULER_WORKER_THREAD; ++ i ) {
        worker[i].SetSerial( i );
    }
}

electron::CConnectionSchedulerMultiThread::~CConnectionSchedulerMultiThread() 
{
}

int electron::CConnectionSchedulerMultiThread::IncRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

int electron::CConnectionSchedulerMultiThread::DecRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

int electron::CConnectionSchedulerMultiThread::GetRef() 
{
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

IInterface * electron::CConnectionSchedulerMultiThread::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectionSchedulerMultiThread::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CConnectionSchedulerMultiThread::OnBegin() 
{
    CObjectPtr object;
    object = CInstanceUtility::MakeObject( nest );
    if( object )
    {
        for( size_t i = 0; i < amount; ++ i )
        {
            if( worker[i].GetActive() == false ) 
            {
                worker[i].SetObject( object );
                worker[i].SetActive( true );
                worker[i].Begin( TP_BELOW_NORMAL );
            }
        }
    }
    return true;
}

bool electron::CConnectionSchedulerMultiThread::OnClose() 
{
    CObjectPtr object;
    for( size_t i = 0; i < amount; ++ i )
    {
        worker[i].SetActive( false );
        worker[i].SetAwaken();
        worker[i].Close( U64(INFINITE) );
        worker[i].SetObject( object );
    }
    return true;
}

void electron::CConnectionSchedulerMultiThread::OnAwake() 
{
    for( size_t i = 0; i < amount; ++ i )
    {
        worker[i].SetAwaken();
    }
}

bool electron::CConnectionSchedulerMultiThread::OnBegin(U32 index) 
{
    bool result = false;
    if( index < amount )
    {
        CObjectPtr object;
        object = CInstanceUtility::MakeObject( nest );

        if( object && 
            worker[index].GetActive() == false )
        {
            worker[index].SetObject( object );
            worker[index].SetActive( true );
            result = worker[index].Begin( TP_BELOW_NORMAL );
        }
    }
    return result;
}

bool electron::CConnectionSchedulerMultiThread::OnClose(U32 index) 
{
    bool result = false;
    if( index < amount )
    {
        CObjectPtr object;

        result = true;
        worker[index].SetActive( false );
        worker[index].SetAwaken();
        worker[index].Close( U64(INFINITE) );
        worker[index].SetObject( object );
    }
    return result;
}

void electron::CConnectionSchedulerMultiThread::OnAwake(U32 index) 
{
    if( index < amount )
    {
        worker[index].SetAwaken();
    }
}

void electron::CConnectionSchedulerMultiThread::SetThreadAmount(U32 totals) 
{
    amount = atom_min( totals, MAX_SCHEDULER_WORKER_THREAD );
    amount = atom_max( amount, 1 );
}

U32 electron::CConnectionSchedulerMultiThread::GetThreadAmount() 
{
    return amount;
}

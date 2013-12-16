#include "CConnectionSchedulerMultiThread.h"
//Begin section for file CConnectionSchedulerMultiThread.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerMultiThread.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerMultiThread::CConnectionSchedulerMultiThread() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
amount(1)
{
    //TODO Auto-generated method stub
    for( U32 i = 0; i < MAX_SCHEDULER_WORKER_THREAD; ++ i ) {
        worker[i].SetSerial( i );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerMultiThread::~CConnectionSchedulerMultiThread() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerMultiThread::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerMultiThread::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerMultiThread::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
IInterface * electron::CConnectionSchedulerMultiThread::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThread::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThread::OnBegin() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThread::OnClose() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThread::OnAwake() 
{
    //TODO Auto-generated method stub
    for( size_t i = 0; i < amount; ++ i )
    {
        worker[i].SetAwaken();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThread::OnBegin(U32 index) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThread::OnClose(U32 index) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThread::OnAwake(U32 index) 
{
    //TODO Auto-generated method stub
    if( index < amount )
    {
        worker[index].SetAwaken();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThread::SetThreadAmount(U32 totals) 
{
    //TODO Auto-generated method stub
    amount = atom_min( totals, MAX_SCHEDULER_WORKER_THREAD );
    amount = atom_max( amount, 1 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CConnectionSchedulerMultiThread::GetThreadAmount() 
{
    //TODO Auto-generated method stub
    return amount;
}

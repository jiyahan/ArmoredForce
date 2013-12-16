#include "CConnectionSchedulerLife.h"
#include "../interface/IConnectionSchedulerController.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CConnectionSchedulerLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerLife::CConnectionSchedulerLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerLife::~CConnectionSchedulerLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerLife::IncRef() 
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
int electron::CConnectionSchedulerLife::DecRef() 
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
int electron::CConnectionSchedulerLife::GetRef() 
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
IInterface * electron::CConnectionSchedulerLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerLife::SetNest(IInterface * value) 
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
bool electron::CConnectionSchedulerLife::Initiate() 
{
    //TODO Auto-generated method stub
    bool result = false;
    CInterface<IConnectionSchedulerController> segment_1;
    if( segment_1.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
        result = segment_1 -> Initiate();
    }

    CInterface<IThreadControl> segment_2;
    if( segment_2.Mount(this, IID_THREAD_CONTROL) ) {
        result = segment_2 -> OnBegin() && result;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerLife::Shutdown() 
{
    //TODO Auto-generated method stub
    bool result = false;
    CInterface<IThreadControl> segment_1;
    if( segment_1.Mount(this, IID_THREAD_CONTROL) ) {
        result = segment_1 -> OnClose();
    }

    CInterface<IConnectionSchedulerController> segment_2;
    if( segment_2.Mount(this, IID_CONNECTION_SCHEDULER_CONTROLLER) ) {
        result = segment_2 -> Shutdown() && result;
    }

    CInterface<IEventEmitter> segment_3;
    if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
        segment_3 -> Detach();
    }

    CInterface<IInstanceAliasContainer<U64> > segment_4;
    if( segment_4.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
        segment_4 -> RemoveAll();
    }

    CInterface<IInstanceContainer> segment_5;
    if( segment_5.Mount(this, IID_INSTANCE_CONTAINER) ) {
        segment_5 -> RemoveAll();
    }
    return result;
}

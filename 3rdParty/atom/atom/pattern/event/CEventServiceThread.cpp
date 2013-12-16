#include "CEventServiceThread.h"
#include "../../utility/tool/CInterface.h"
#include "../../interface/IEventServiceTimeline.h"
#include "../../interface/IEventSpaceController.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CEventServiceThread.cpp
//TODO: Add definitions that you want preserved
//End section for file CEventServiceThread.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceThread::CEventServiceThread() : 
CThread("Event Service"),nest(NULL),active(false)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CEventServiceThread::~CEventServiceThread() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceThread::SetActive(bool value) 
{
    //TODO Auto-generated method stub
    active = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceThread::GetActive() 
{
    //TODO Auto-generated method stub
    return active;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventServiceThread::IncRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventServiceThread::DecRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CEventServiceThread::GetRef() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CEventServiceThread::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceThread::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) nest = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceThread::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceThread::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CEventServiceThread::Run() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceThread::OnBegin() 
{
    //TODO Auto-generated method stub
    SetActive( true );
    return Begin( TP_BELOW_NORMAL );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CEventServiceThread::OnClose() 
{
    //TODO Auto-generated method stub
    SetActive( false );
	OnAwake();
    Close( U64(INFINITE) );
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CEventServiceThread::OnAwake() 
{
    //TODO Auto-generated method stub
	signal.Awake();
}

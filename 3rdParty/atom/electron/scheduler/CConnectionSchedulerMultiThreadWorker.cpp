#include "CConnectionSchedulerMultiThreadWorker.h"
#include "../interface/IConnectionSchedulerController.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CConnectionSchedulerMultiThreadWorker.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerMultiThreadWorker.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerMultiThreadWorker::CConnectionSchedulerMultiThreadWorker() : 
CThread("Connection scheduler worker"),serial(0),active(false)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerMultiThreadWorker::~CConnectionSchedulerMultiThreadWorker() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 electron::CConnectionSchedulerMultiThreadWorker::Run() 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThreadWorker::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThreadWorker::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThreadWorker::SetObject(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    object = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThreadWorker::SetActive(bool value) 
{
    //TODO Auto-generated method stub
    active = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThreadWorker::SetAwaken() 
{
    //TODO Auto-generated method stub
    signal.Awake();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerMultiThreadWorker::SetSerial(U32 value) 
{
    //TODO Auto-generated method stub
    serial = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerMultiThreadWorker::GetActive() 
{
    //TODO Auto-generated method stub
    return active;
}

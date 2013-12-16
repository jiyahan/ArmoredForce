#include "CTcpKQueueModelThreadWorker.h"
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpKQueueModelThreadWorker.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpKQueueModelThreadWorker.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueModelThreadWorker::CTcpKQueueModelThreadWorker() :
CThread( "KQueue worker" ),serial( U32(INFINITE) )
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueModelThreadWorker::~CTcpKQueueModelThreadWorker() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpKQueueModelThreadWorker::Run() 
{
    //TODO Auto-generated method stub
    CObjectPtr nest = object;
    if( nest )
    {
		CInterface<ITcpKQueueIOModel> segment;
		if( segment.Mount(nest, IID_TCP_KQUEUE_IO_MODEL) ) {
			segment -> OnProcess( serial );
        }
    }
    return 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreadWorker::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueModelThreadWorker::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreadWorker::SetObject(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    object = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueModelThreadWorker::SetSerial(U32 value) 
{
    //TODO Auto-generated method stub
    serial = value;
}

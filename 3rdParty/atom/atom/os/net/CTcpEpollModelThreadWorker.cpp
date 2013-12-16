#include "CTcpEpollModelThreadWorker.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpEpollModelThreadWorker.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollModelThreadWorker.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelThreadWorker::CTcpEpollModelThreadWorker() : 
CThread("Epoll worker"),serial( U32(INFINITE) )
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollModelThreadWorker::~CTcpEpollModelThreadWorker() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpEpollModelThreadWorker::Run() 
{
    //TODO Auto-generated method stub
    CObjectPtr nest = object;
    if( nest )
    {
		CInterface<ITcpEpollIOModel> segment;
		if( segment.Mount(nest, IID_TCP_EPOLL_IO_MODEL) ) {
			segment -> OnProcess( serial );
        }
    }
    return 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreadWorker::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollModelThreadWorker::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreadWorker::SetObject(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    object = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollModelThreadWorker::SetSerial(U32 value) 
{
    //TODO Auto-generated method stub
    serial = value;
}

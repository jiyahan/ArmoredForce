#include "CTcpIocpModelThreadWorker.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpIocpModelThreadWorker.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpIocpModelThreadWorker.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelThreadWorker::CTcpIocpModelThreadWorker() :
CThread( "IOCP worker" ),serial( U32(INFINITE) )
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpIocpModelThreadWorker::~CTcpIocpModelThreadWorker() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpIocpModelThreadWorker::Run() 
{
    //TODO Auto-generated method stub
    CObjectPtr nest = object;
    if( nest )
    {
		CInterface<ITcpIocpIOModel> segment;
		if( segment.Mount(nest, IID_TCP_IOCP_IO_MODEL) ) {
			segment -> OnProcess( serial );
        }
    }
    return 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreadWorker::OnThreadBegin() 
{
    //TODO Auto-generated method stub
	#ifdef _DEBUG
	printf( "IOCP thread started.\n" );
	#endif
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpIocpModelThreadWorker::OnThreadClose() 
{
    //TODO Auto-generated method stub
	#ifdef _DEBUG
	printf( "IOCP thread stoped.\n" );
	#endif
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreadWorker::SetObject(CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    object = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpIocpModelThreadWorker::SetSerial(U32 value) 
{
    //TODO Auto-generated method stub
    serial = value;
}

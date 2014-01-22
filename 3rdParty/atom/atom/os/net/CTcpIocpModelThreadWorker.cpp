#include "CTcpIocpModelThreadWorker.h"
#include "../../interface/ITcpIocpIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpIocpModelThreadWorker::CTcpIocpModelThreadWorker() :
CThread( "IOCP worker" ),serial( U32(INFINITE) )
{
}

atom::CTcpIocpModelThreadWorker::~CTcpIocpModelThreadWorker() 
{
}

U32 atom::CTcpIocpModelThreadWorker::Run() 
{
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

bool atom::CTcpIocpModelThreadWorker::OnThreadBegin() 
{
	#ifdef _DEBUG
	printf( "IOCP thread started.\n" );
	#endif
    return true;
}

bool atom::CTcpIocpModelThreadWorker::OnThreadClose() 
{
	#ifdef _DEBUG
	printf( "IOCP thread stoped.\n" );
	#endif
    return true;
}

void atom::CTcpIocpModelThreadWorker::SetObject(CObjectPtr & value) 
{
    object = value;
}

void atom::CTcpIocpModelThreadWorker::SetSerial(U32 value) 
{
    serial = value;
}

#include "CTcpEpollModelThreadWorker.h"
#include "../../interface/ITcpEpollIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpEpollModelThreadWorker::CTcpEpollModelThreadWorker() : 
CThread("Epoll worker"),serial( U32(INFINITE) )
{
}

atom::CTcpEpollModelThreadWorker::~CTcpEpollModelThreadWorker() 
{
}

U32 atom::CTcpEpollModelThreadWorker::Run() 
{
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

bool atom::CTcpEpollModelThreadWorker::OnThreadBegin() 
{
    return true;
}

bool atom::CTcpEpollModelThreadWorker::OnThreadClose() 
{
    return true;
}

void atom::CTcpEpollModelThreadWorker::SetObject(CObjectPtr & value) 
{
    object = value;
}

void atom::CTcpEpollModelThreadWorker::SetSerial(U32 value) 
{
    serial = value;
}

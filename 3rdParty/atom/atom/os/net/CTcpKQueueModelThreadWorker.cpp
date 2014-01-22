#include "CTcpKQueueModelThreadWorker.h"
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../utility/tool/CInterface.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CTcpKQueueModelThreadWorker::CTcpKQueueModelThreadWorker() :
CThread( "KQueue worker" ),serial( U32(INFINITE) )
{
}

atom::CTcpKQueueModelThreadWorker::~CTcpKQueueModelThreadWorker() 
{
}

U32 atom::CTcpKQueueModelThreadWorker::Run() 
{
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

bool atom::CTcpKQueueModelThreadWorker::OnThreadBegin() 
{
    return true;
}

bool atom::CTcpKQueueModelThreadWorker::OnThreadClose() 
{
    return true;
}

void atom::CTcpKQueueModelThreadWorker::SetObject(CObjectPtr & value) 
{
    object = value;
}

void atom::CTcpKQueueModelThreadWorker::SetSerial(U32 value) 
{
    serial = value;
}

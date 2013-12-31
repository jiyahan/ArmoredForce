//#include "stdafx.h"
#include "SocketServer.h"
#include "CClientEventHandle.h"


using namespace std;
using namespace atom;
using namespace electron;


#define LISTEN_THREAD_NUM   1

namespace {

    static CClientEventHandle       nest;

} // anonymous namespace


SocketServer::SocketServer(void)
{
}


SocketServer::~SocketServer(void)
{
}

bool SocketServer::Start(const string& host, U16 port)
{
    //初始化
    CObjectPtr phase = &nest;
    CObjectPtr space = CInstanceUtility::ObtainInstance(
        CConnectionScheduler::GetInstance()->GetEventSpace() );
    if( phase && space )
    {
        CInterface<IEventSpaceController> segment_4;
        if( segment_4.Mount(space, IID_EVENT_SPACE_CONTROLLER) ) {
            bool step_4 = segment_4->Attach( phase );
            if(!step_4)
            {
                return false;
            }
        }
    }

    msg_queue_ = CInstanceUtility::CreateInstance( OID_MESSAGE_QUEUE );
    if( msg_queue_ )
    {
        // keep message queue's life reference
        CInstanceLife::GetInstance()->Increase( msg_queue_->GetName() );

        CInterface<IMessageQueueController> segment;
        if( segment.Mount(msg_queue_, IID_MESSAGE_QUEUE_CONTROLLER) ) 
        {
            segment->SetQueueAmount( LISTEN_THREAD_NUM );
#if defined(_WIN32)
            U32 io_model = OID_TCP_IOCP_MODEL;
#elif defined(__linux__)
            U32 io_model = OID_TCP_EPOLL_MODEL
#endif
            listener_ = CConnectionScheduler::GetInstance()->Listen( 
                host.c_str(), port, io_model, msg_queue_->GetName() );
            return true;
        }
    }
    return false;
}

void SocketServer::Close()
{
    CConnectionScheduler::GetInstance()->Close( listener_ );

    // decrease message queue's life reference
    CInstanceLife::GetInstance()->Decrease( msg_queue_->GetName() );
    CInstanceUtility::ShutdownInstance(msg_queue_);
}

void SocketServer::GetSocketMessage(CMessageQueueControllerSetBind& messages)
{ 
    if( msg_queue_ )
    {
        CInterface<IMessageQueueController> segment;
        if( segment.Mount(msg_queue_, IID_MESSAGE_QUEUE_CONTROLLER) ) 
        {
            for( size_t i = 0; i < LISTEN_THREAD_NUM; ++ i ) 
            {
                segment->Obtain( i, messages );
                //segment -> Repose( i, 1000 );
            }
        }
    }
}


//发送消息
void SocketServer::Send(U64 connector, CMessage& msg)
{
    CConnectionScheduler::GetInstance()->Send( connector, &msg );
}

void SocketServer::CloseAConnection(U64 connector)
{
    CConnectionScheduler::GetInstance()->Close( connector );
}

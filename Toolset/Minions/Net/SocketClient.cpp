#include "StdAfx.h"
#include "SocketClient.h"
#include "CClientEventHandle.h"


#define THREAD_AMOUNT   1


using namespace std;
using namespace atom;
using namespace electron;


SocketClient::SocketClient(void)
{
}


SocketClient::~SocketClient(void)
{
}


static CClientEventHandle nest;


bool SocketClient::Start(const char* ip,U16 port)
{
	//初始化
	CObjectPtr phase = &nest;
	CObjectPtr space = CInstanceUtility::ObtainInstance(
		CConnectionScheduler::GetInstance() -> GetEventSpace() );
	if( phase && space )
	{
		CInterface<IEventSpaceController> segment_4;
		if( segment_4.Mount(space, IID_EVENT_SPACE_CONTROLLER) ) 
        {
			bool step_4 = segment_4 -> Attach( phase );
			if(!step_4)
			{
				return false;
			}
		}
	}

	//初始化	
	msg_queue_ = CInstanceUtility::CreateInstance( OID_MESSAGE_QUEUE );
	if( msg_queue_ )
	{
		// keep message queue's life reference
		CInstanceLife::GetInstance() -> Increase( msg_queue_ -> GetName() );

		CInterface<IMessageQueueController> segment;
		if( segment.Mount(msg_queue_, IID_MESSAGE_QUEUE_CONTROLLER) ) 
		{
			segment -> SetQueueAmount( THREAD_AMOUNT );
			
			bool succeeded = true;
			client_id_ = CConnectionScheduler::GetInstance() -> Connect( 
				ip, port, OID_TCP_SELECT_MODEL, msg_queue_ -> GetName() );
			succeeded = client_id_ && succeeded;
			return succeeded;
		}
	}
	return false;
}

void SocketClient::Close()
{
	 CConnectionScheduler::GetInstance() -> Close( client_id_ );

	 // decrease message queue's life reference
	 CInstanceLife::GetInstance()->Decrease( msg_queue_ -> GetName() );
	 CInstanceUtility::ShutdownInstance( msg_queue_ );
}


void SocketClient::Send(CMessage& msg)
{
	CConnectionScheduler::GetInstance() -> Send( client_id_, & msg );
}


void SocketClient::GetSocketMessage(CMessageQueueControllerSetBind &messages)
{ 
	if( msg_queue_ )
	{
		CInterface<IMessageQueueController> segment;
		if( segment.Mount(msg_queue_, IID_MESSAGE_QUEUE_CONTROLLER) ) 
		{
			for( size_t i = 0; i < THREAD_AMOUNT; ++ i ) 
			{
				segment -> Obtain( i, messages );
				//segment -> Repose( i, 1000 );
			}
		}
	}
}
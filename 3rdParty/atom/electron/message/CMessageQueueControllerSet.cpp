#include "CMessageQueueControllerSet.h"


electron::CMessageQueueControllerSet::CMessageQueueControllerSet() 
{
}

electron::CMessageQueueControllerSet::~CMessageQueueControllerSet() 
{
}

bool electron::CMessageQueueControllerSet::Insert(CMessage * message) 
{
    if( !message ) return false;

	section.Enter(); queue.push_back( message ); 
    section.Leave();
	return true;
}

bool electron::CMessageQueueControllerSet::Obtain(CMessageQueueControllerSetBind & out) 
{
    // 准备交换队列，并将交换队列的大小控制到100个；
    CMessageQueueControllerSetBind swap; 
    swap.reserve( 128 );

    // 交换出所有的消息，并将消息拷贝到输出队列内；
    section.Enter(); swap.swap( queue );
	section.Leave();

    size_t reserve = out.size() + swap.size();
    reserve = ( reserve / 128 + 1 ) * 128;

    out.reserve( reserve );
    std::copy( swap.begin(), swap.end(), back_inserter(out) );
	return true;
}

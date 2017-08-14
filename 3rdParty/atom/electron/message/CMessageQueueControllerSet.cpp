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
    // ׼���������У������������еĴ�С���Ƶ�100����
    CMessageQueueControllerSetBind swap; 
    swap.reserve( 128 );

    // ���������е���Ϣ��������Ϣ��������������ڣ�
    section.Enter(); swap.swap( queue );
	section.Leave();

    size_t reserve = out.size() + swap.size();
    reserve = ( reserve / 128 + 1 ) * 128;

    out.reserve( reserve );
    std::copy( swap.begin(), swap.end(), back_inserter(out) );
	return true;
}

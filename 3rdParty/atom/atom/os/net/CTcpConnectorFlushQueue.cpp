#include "CTcpConnectorFlushQueue.h"
#include "../../utility/tool/CCriticalSectionScope.h"


atom::CTcpConnectorFlushQueue::CTcpConnectorFlushQueue() : 
length(0),offset(0)
{
}

atom::CTcpConnectorFlushQueue::~CTcpConnectorFlushQueue() 
{
}

void atom::CTcpConnectorFlushQueue::Clear() 
{
    CCriticalSectionScope scope( section );
	queued.clear();
	length = 0;
	offset = 0;
}

bool atom::CTcpConnectorFlushQueue::IsEmpty() 
{
	section.Enter();
	bool result( length == 0 );
	section.Leave();

	return result;
}

void atom::CTcpConnectorFlushQueue::Append(CMemory & data) 
{
    size_t value( data.GetLength() );
	if( value )
	{
    	section.Enter();
    	queued.push_back( data ); length += value;
    	section.Leave();
	}
}

bool atom::CTcpConnectorFlushQueue::Obtain(CMemory & output, size_t & locate) 
{
	bool result = false;
	section.Enter();
	if( !queued.empty() )
	{
        result = true;
    	output = queued.front();
    	locate = offset;
	}
	section.Leave();
	return result;
}

size_t atom::CTcpConnectorFlushQueue::Length() 
{
    CCriticalSectionScope scope( section );
	return length; 
}

bool atom::CTcpConnectorFlushQueue::Change(CTcpConnectorFlushQueueBind & value) 
{
    bool result = false;
    if( !value.empty() )
    {
        // 进入临界区，并判断是否需要交换；
        section.Enter();
        if( queued.empty() )
        {
            offset = 0;
            length = 0;
            result = true;

            // 交换容器，并遍历容器，计算待发送的数据长度；
            queued.swap( value );
            for( CTcpConnectorFlushQueueBind::iterator 
                it = queued.begin(); it != queued.end(); ++ it ) {
                length += it -> GetLength();
            }
        }
		section.Leave();
    }
    return result;
}

bool atom::CTcpConnectorFlushQueue::IncreaseOffset(size_t value) 
{
	bool result = false;
	section.Enter();
	if( !queued.empty() )
	{
    	// 如果位移是一个有效的值，那么继续。
		if( offset + value <= length )
		{
            result = true; offset += value;
		    	
			// 清理已经使用完了的内存块。
			size_t tempOffset = 0;
			CTcpConnectorFlushQueueBind::iterator it = queued.begin();
			for( ; it != queued.end(); )
			{
				// 判断这个块是否可以移出。
                // 如果内存块的长度加临时偏移量大于偏移量，则代表该内存块内有值，终止循环；
				if( tempOffset + it -> GetLength() > offset ) break;
		
                // 如果内存块的长度小于等于偏移量，则代表该内存块内数据已完成发送，删除；
				tempOffset += it -> GetLength();
				it = queued.erase( it );
			}
		
			// 循环终止后，减少流的长度和位移
			if( tempOffset )
			{
				offset -= tempOffset;
				length -= tempOffset;
			}
		}
	}
	section.Leave();
	return result;
}

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
        // �����ٽ��������ж��Ƿ���Ҫ������
        section.Enter();
        if( queued.empty() )
        {
            offset = 0;
            length = 0;
            result = true;

            // ������������������������������͵����ݳ��ȣ�
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
    	// ���λ����һ����Ч��ֵ����ô������
		if( offset + value <= length )
		{
            result = true; offset += value;
		    	
			// �����Ѿ�ʹ�����˵��ڴ�顣
			size_t tempOffset = 0;
			CTcpConnectorFlushQueueBind::iterator it = queued.begin();
			for( ; it != queued.end(); )
			{
				// �ж�������Ƿ�����Ƴ���
                // ����ڴ��ĳ��ȼ���ʱƫ��������ƫ�������������ڴ������ֵ����ֹѭ����
				if( tempOffset + it -> GetLength() > offset ) break;
		
                // ����ڴ��ĳ���С�ڵ���ƫ�������������ڴ������������ɷ��ͣ�ɾ����
				tempOffset += it -> GetLength();
				it = queued.erase( it );
			}
		
			// ѭ����ֹ�󣬼������ĳ��Ⱥ�λ��
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

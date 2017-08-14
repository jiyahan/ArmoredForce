#include "CTcpConnectorFlushQueue.h"
#include "../../utility/tool/CCriticalSectionScope.h"
//Begin section for file CTcpConnectorFlushQueue.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorFlushQueue.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorFlushQueue::CTcpConnectorFlushQueue() : 
length(0),offset(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorFlushQueue::~CTcpConnectorFlushQueue() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorFlushQueue::Clear() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
	queued.clear();
	length = 0;
	offset = 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushQueue::IsEmpty() 
{
    //TODO Auto-generated method stub
	section.Enter();
	bool result( length == 0 );
	section.Leave();

	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorFlushQueue::Append(CMemory & data) 
{
    //TODO Auto-generated method stub
    size_t value( data.GetLength() );
	if( value )
	{
    	section.Enter();
    	queued.push_back( data ); length += value;
    	section.Leave();
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushQueue::Obtain(CMemory & output, size_t & locate) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CTcpConnectorFlushQueue::Length() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
	return length; 
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushQueue::Change(CTcpConnectorFlushQueueBind & value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushQueue::IncreaseOffset(size_t value) 
{
    //TODO Auto-generated method stub
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

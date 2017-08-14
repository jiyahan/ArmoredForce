#include "CTcpConnectorFlushDevice.h"
#include "CTcpNetworkService.h"
#include "../../log/CLog.h"
#include "../../interface/ITcpIOModel.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CTcpConnectorFlushDevice.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorFlushDevice.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorFlushDevice::CTcpConnectorFlushDevice() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
connect(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorFlushDevice::~CTcpConnectorFlushDevice() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpConnectorFlushDevice::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpConnectorFlushDevice::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpConnectorFlushDevice::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CTcpConnectorFlushDevice::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorFlushDevice::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushDevice::OnFlush(CMemory & data) 
{
    //TODO Auto-generated method stub
    // �Ƚ�����д����У�
    protect.Enter();
    waiting.push_back( data );
	protect.Leave();

    // ����һ�η��Ͳ�����
    Send();
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushDevice::Bind(U32 mold) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( mold && nest )
	{
		CCriticalSectionScope scope( section );
		connect = CInstanceUtility::GetInstanceName( nest );
		iomodel = CTcpNetworkService::GetInstance() -> GetModel( mold );

		if( connect && iomodel ) {
			result = true;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorFlushDevice::OnDataSent(size_t bytes) 
{
    //TODO Auto-generated method stub
	bool result = true;	
	if( bytes ) {
		result = prepare.IncreaseOffset( bytes );
	}

    // ���Դ�ӡ
    if( !result ) {
        CLog log;
        log << "Tcp flush device FAILED increase queue offset! bytes: "
            << U64(bytes) << end_error;
    }

    // �������ü������������ύһ�η�������
    counter.Decrease(); Send();
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorFlushDevice::Reset() 
{
    //TODO Auto-generated method stub
	prepare.Clear(); 
        
    protect.Enter();
    waiting.clear();
    protect.Leave();

    section.Enter();
	connect = 0;
	iomodel = NULL; 
	section.Leave();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CTcpConnectorFlushDevice::Send() 
{
    //TODO Auto-generated method stub
    // Send������OnDataSent������ͬ�����һ��ѭ��������Send
    // ��ʼ����OnDataSent�������ɼ������γ���һ�����̷߳���
    // �Ļ�����������Ϊ 1��ʱ�򣬴�����̻߳�������������
    // ����Ȩ����Send������ʱ�򣬼�������δ���ټ�������ˣ�
    // �����߳����ɲ����÷���Ȩ����IO�߳̽�������ʱ��֪ͨ
    // �豸������ʹ�ù�����ڴ棬�����ټ������Ӷ�����һ����
    // �ڡ�


    // ���������Ϊ1�������ǰ���������߳����ڷ������ݣ�
    // �򲻴�����ֱ��������
    if( counter.Increase() != 1 ) {
        counter.Decrease(); return 0;
    }

    // �����������Ϊ�գ������ݽ������룻
    if( prepare.IsEmpty() )
    {
        // �����ٽ����������Խ����ݽ������̵߳Ķ�ջ�ϣ�
        protect.Enter();

        // �������Ϊ�գ������ٽ����ڼ������ü�������Ϊ�� OnFlush��
        // ʱ�򣬻��Ƚ����ٽ�����д�����ݣ��˳��ٽ���֮���ټ���
        // �����Ƿ�Ϊ 1�������Է������ݣ������Ϊ 1����ô�����̻߳�
        // �����������̡���ˣ�����һ����������IO�̷߳��������ݣ�
        // �����ٴγ��Է�������ʱ�����ִ�ʱ�ȴ������������ݣ�׼����
        // ���������̣�����ʱ��������һ���߼��̳߳��Է������ݣ����
        // �����ٽ����ڼ��ټ����������ڼ����˳��ٽ�����֮���ټ���
        // ����������ô�Ϳ��ܳ��������߳�ͬʱ�������Ͳ����������ֻ
        // Ҫ���ٽ����ڼ��ټ��������ͻ�ͨ���ٽ�����Ȼ�Ļرܸ������
        // ������
        if( waiting.empty() ) 
		{
            counter.Decrease(); protect.Leave();
			return 0;
        }
		else 
		{
			// �ڴ˹���data������ÿһ�ζ������������
	        CTcpConnectorFlushQueue::CTcpConnectorFlushQueueBind data;
            data.swap(waiting); protect.Leave();

			// ���̶߳�ջ�ϵ����ݽ����������ڣ�������� false��������
			// �����޷��ָ��Ĵ��󣡴�ӡ������䣻���ڴ˴��ĵ��̻߳�����
			// ��ˣ������ܴ���IO�߳�ִ��ɾ��������ǰ̨�߳�ִ����ӵ���
			// ����Ҳ�����ܴ�������ǰ̨�߳�ͬʱִ����ӵ������
			if( !prepare.Change( data ) ) {
				CLog log;
				log << "Tcp flush device prepare change data failed !" << end_error;
			}
		}
    }

    // ׼��������
    CMemory data;
	size_t result(0), offset(0), length(0); 

    // �Ӷ����ڻ�ȡ���ݣ����ж����ݵ���Ч�ԣ�
	if( prepare.Obtain(data, offset) && data.GetLength() > offset )
	{
		// �����Ҫ���͵ĳ��ȡ�
		length = data.GetLength() - offset;

        // ���������ٽ��������������ݣ�
        section.Enter();
		if( connect && iomodel )
        {
			CInterface<ITcpIOModel> segment;
			if( segment.Mount(iomodel, IID_TCP_IO_MODEL) )
			{
				// ���Է������ݣ�
				if( segment -> Send(connect, data, offset, length) ) {
					result = length;
				}
			}
        }
		section.Leave();
	}

    // �������ʧ�ܣ�����ټ������������أ���ʱ�����ڲ������ݽ�
    // �޷������ͣ�ֱ����һ�η�������ʱ����������һ��δ��ɵķ�
    // �͡�
    if( result == 0 ) counter.Decrease();

	return result;
}

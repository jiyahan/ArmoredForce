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
    // 先将数据写入队列；
    protect.Enter();
    waiting.push_back( data );
	protect.Leave();

    // 尝试一次发送操作；
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

    // 调试打印
    if( !result ) {
        CLog log;
        log << "Tcp flush device FAILED increase queue offset! bytes: "
            << U64(bytes) << end_error;
    }

    // 减少引用计数，并继续提交一次发送请求；
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
    // Send函数与OnDataSent函数共同组成了一个循环，即由Send
    // 开始，到OnDataSent结束，由计数器形成了一个单线程访问
    // 的环境。当计数为 1的时候，代表该线程获得了这个环境的
    // 访问权。当Send结束的时候，计数器并未减少计数，因此，
    // 其他线程依旧不会获得访问权，而IO线程结束发送时，通知
    // 设备，销毁使用过后的内存，并减少计数，从而结束一个周
    // 期。


    // 如果计数不为1，则代表当前还有其他线程正在发送数据，
    // 则不处理，并直接跳过；
    if( counter.Increase() != 1 ) {
        counter.Decrease(); return 0;
    }

    // 如果就绪队列为空，则将数据交换进入；
    if( prepare.IsEmpty() )
    {
        // 进入临界区，并尝试将数据交换到线程的堆栈上；
        protect.Enter();

        // 如果数据为空，则在临界区内减少引用计数！因为在 OnFlush的
        // 时候，会先进入临界区并写入数据，退出临界区之后，再检查计
        // 数器是否为 1，并尝试发送数据！如果不为 1，那么发送线程会
        // 跳过发送流程。因此，存在一个情况，如果IO线程发送完数据，
        // 并且再次尝试发送数据时，发现此时等待队列内无数据，准备退
        // 出发送流程，而此时，有另外一个逻辑线程尝试发送数据，如果
        // 不在临界区内减少计数，而是在检查后退出临界区，之后再减少
        // 计数器，那么就可能出现两个线程同时放弃发送操作的情况！只
        // 要在临界区内减少计数器，就会通过临界区天然的回避该问题的
        // 产生。
        if( waiting.empty() ) 
		{
            counter.Decrease(); protect.Leave();
			return 0;
        }
		else 
		{
			// 在此构造data，避免每一次都构造这个对象；
	        CTcpConnectorFlushQueue::CTcpConnectorFlushQueueBind data;
            data.swap(waiting); protect.Leave();

			// 将线程堆栈上的数据交换到队列内；如果返回 false，则代表出
			// 现了无法恢复的错误！打印调试语句；由于此处的单线程环境，
			// 因此，不可能存在IO线程执行删除操作，前台线程执行添加的情
			// 况，也不可能存在两个前台线程同时执行添加的情况。
			if( !prepare.Change( data ) ) {
				CLog log;
				log << "Tcp flush device prepare change data failed !" << end_error;
			}
		}
    }

    // 准备变量；
    CMemory data;
	size_t result(0), offset(0), length(0); 

    // 从队列内获取数据，并判断数据的有效性；
	if( prepare.Obtain(data, offset) && data.GetLength() > offset )
	{
		// 求出需要发送的长度。
		length = data.GetLength() - offset;

        // 进入连接临界区，并发送数据；
        section.Enter();
		if( connect && iomodel )
        {
			CInterface<ITcpIOModel> segment;
			if( segment.Mount(iomodel, IID_TCP_IO_MODEL) )
			{
				// 尝试发送数据；
				if( segment -> Send(connect, data, offset, length) ) {
					result = length;
				}
			}
        }
		section.Leave();
	}

    // 如果发送失败，则减少计数器，并返回，此时队列内部的数据将
    // 无法被发送，直到下一次发送数据时，将继续上一次未完成的发
    // 送。
    if( result == 0 ) counter.Decrease();

	return result;
}

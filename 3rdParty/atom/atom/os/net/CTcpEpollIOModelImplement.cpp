#include "CTcpEpollIOModelImplement.h"
#include "utility/CSocketUtility.h"
#include "../system/CSystemInformation.h"
#include "../../utility/stl/CU32Array.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IEventEmitter.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../interface/ITcpConnectionController.h"
#include "../../interface/ITcpListenerController.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IImportStream.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CTcpEpollIOModelImplement.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpEpollIOModelImplement.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollIOModelImplement::CTcpEpollIOModelImplement() : 
nest(NULL)
#ifdef __linux
,amount(1),active(false)
#endif
{
    //TODO Auto-generated method stub
	#ifdef __linux
	memset( epolls, 0, sizeof(epolls) );
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpEpollIOModelImplement::~CTcpEpollIOModelImplement() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpEpollIOModelImplement::IncRef() 
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
int atom::CTcpEpollIOModelImplement::DecRef() 
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
int atom::CTcpEpollIOModelImplement::GetRef() 
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
atom::IInterface * atom::CTcpEpollIOModelImplement::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollIOModelImplement::SetNest(IInterface * value) 
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
SOCKET atom::CTcpEpollIOModelImplement::Create() 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	
	SOCKET result = socket( AF_INET, SOCK_STREAM, 0 );
	if( result != INVALID_SOCKET )
	{
		int value;
		if( ( ( value = fcntl(result, F_GETFL) ) == -1 ) ||
			( fcntl( result, F_SETFL, value | O_NONBLOCK ) == -1 ) )
		{
			// if failed, close socket。
			close( result ); result = INVALID_SOCKET;
		}
	}
	return result;
	
	#else 

	return INVALID_SOCKET;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollIOModelImplement::Remove(SOCKET hs) 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	if( hs != INVALID_SOCKET ) close( hs );
	#else
	UNREFERENCED_PARAMETER(hs);
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Attach(U64 name) 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	if( !name ) return false;
	bool result = false;

	if( amount && amount <= MAX_EPOLL_THREAD )
	{
		CObjectPtr object = 
			CInstanceFactory::GetInstance() -> Inquire( name );
		if( object )
		{
			SOCKET hs = INVALID_SOCKET;
			CInterface<ITcpConnectionController> controller;
			if( controller.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = controller -> GetSocket();
			}

			if( INVALID_SOCKET != hs )
			{
				CInterface<IInstanceContainer> segment;
				if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) 
				{
					if( segment -> Insert(object) )
					{
						epoll_event ent;
						ent.data.u64 = name;
						ent.events   = EPOLLIN | EPOLLERR;

						if( object -> GetType() == OID_TCP_CONNECTOR ) {
							ent.events |= EPOLLET;
						}
					
						result = ( epoll_ctl(epolls[hs % amount], EPOLL_CTL_ADD, hs, & ent) == 0 );

						if( result == false ) {
							segment -> Remove( name );
						}
					}
				}
			}
		}
	}
    return result;

	#else
	
	UNREFERENCED_PARAMETER( name );
	return false;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Detach(U64 name) 
{
    //TODO Auto-generated method stub
	#ifdef __linux

	bool result = false;
	if( name && amount && amount <= MAX_EPOLL_THREAD )
	{
		CObjectPtr object = Obtain( name );
		if( object )
		{
			SOCKET hs = INVALID_SOCKET;

			CInterface<ITcpConnectionController> controller;
			if( controller.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = controller -> GetSocket();
			}

			if( hs != INVALID_SOCKET )
			{
				CInterface<IInstanceContainer> segment;
				if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) 
				{
					result = segment -> Remove( name );
					epoll_ctl( epolls[hs % amount], EPOLL_CTL_DEL, hs, NULL );
				}
			}
		}
	}
    return result;

	#else

	UNREFERENCED_PARAMETER( name );
	return false;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpEpollIOModelImplement::Obtain(U64 name) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	#ifdef __linux
	if( name )
	{
		CInterface<IInstanceContainer> segment;
		if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
			result = segment -> Obtain( name );
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	#endif
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;

	#ifdef __linux
	result = true;
	amount = static_cast<U32>( ( CSystemInformation::GetProcessorCount() + 5 ) / 2 * 2 );
	amount = atom_max( amount, 1 );
	amount = atom_min( amount, MAX_EPOLL_THREAD );

	for( U32 i = 0; i < amount; ++ i ) {
		result = ( ( epolls[i] = epoll_create(MAX_EPOLL_LENGTH) ) != -1 ) && result;
	}
	
	active = result;
	#endif

	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Shutdown() 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	for( U32 i = 0; i < amount; ++ i ) {
		if( epolls[i] == 0 || epolls[i] == -1 ) continue;
		close( epolls[i] );
	}

	memset( epolls, 0, sizeof(epolls) );
	#endif

    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Listen(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
	#ifdef __linux

	bool result = false;
	if( name && domain.host.length() && domain.port )
	{
		CObjectPtr listener = Obtain( name );
		if( listener )
		{
			SOCKET hs = INVALID_SOCKET;

			CInterface<ITcpConnectionController> segment;
			if( segment.Mount(listener, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = segment -> GetSocket();
			}

			if( hs != INVALID_SOCKET )
			{
				// 首先准备好地址的结构体
				sockaddr_in address;
				memset( & address, 0, sizeof(address) );

				address.sin_family      = AF_INET;
				address.sin_port        = htons( domain.port );
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );

				// 绑定该地址上的该端口给hs。
				if( SOCKET_ERROR != 
					::bind( hs, reinterpret_cast<sockaddr*>(& address), 
					sizeof(sockaddr_in) ) ) {
					result = ( listen(hs, 32) != SOCKET_ERROR );
				}
			}
		}
	}
	return result;

	#else

	UNREFERENCED_PARAMETER( name );
	UNREFERENCED_PARAMETER( domain );
	return false;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Connect(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
	#ifdef __linux

	bool result = false;
	if( name && domain.host.length() && domain.port )
	{
		CObjectPtr connector = Obtain( name );
		if( connector )
		{
			SOCKET hs = INVALID_SOCKET;

			CInterface<ITcpConnectionController> segment;
			if( segment.Mount(connector, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = segment -> GetSocket();
			}

			if( hs != INVALID_SOCKET )
			{
				sockaddr_in address;
				memset( & address, 0, sizeof(address) );

				address.sin_family      = AF_INET;
				address.sin_port        = htons( domain.port );
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );

				// connect to domain;
				result = ( 0 == connect( hs, 
					reinterpret_cast<sockaddr*>(& address), sizeof(sockaddr_in) ) );
				if( result == false ) {
					result = ( errno == EINPROGRESS );
				}
			}
		}
	}
	return result;
	
	#else

	UNREFERENCED_PARAMETER( name );
	UNREFERENCED_PARAMETER( domain );
	return false;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Send(U64 name, CMemory & data, size_t offset, size_t length) 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	
	// 该函数由逻辑线程或者流控制线程主动调用，如果发送完毕，则正常结束，如果调用
	// 过程中，被阻塞，则重置EPOLL事件，监听OUT事件。当事件被触发时，由EPOLL线程
	// 负责继续处理未发送完整的数据，并由EPOLL线程负责清理OUT标志。
	if( name == 0 || length == 0 || data.GetLength() < offset + length ) {
		return false;
	}

	bool result = false;
	CObjectPtr connector = Obtain( name );
	if( connector )
	{
		CInterface<ITcpConnectionController> segment;
		if( segment.Mount(connector, IID_TCP_CONNECTION_CONTROLLER) )
		{
			SOCKET hs = segment -> GetSocket();
			if( hs != INVALID_SOCKET )
			{
				//ssize_t bytes = write( hs, data.Query<char>() + offset, length );
				ssize_t bytes = send( hs, 
					data.Query<char>() + offset, static_cast<int>(length), MSG_NOSIGNAL );
				if( bytes == -1 ) 
				{
					// 如果返回-1，并且是因为写入缓冲区已满导致的错误返回，那么此时就不再进
					// 行任何处理，无须做任何事情，仅需等待EPoll的写入就绪通知。如果是其他
					// 原因导致的错误，那么就表示连接失效。
					if( errno == EAGAIN )
					{
						// Modify epoll event
						epoll_event ent;
						ent.data.u64 = name;
						ent.events   = EPOLLOUT | EPOLLIN | EPOLLET | EPOLLERR;
						
						result = ( epoll_ctl( epolls[hs % amount], EPOLL_CTL_MOD, hs, & ent ) == 0 );
					}
				} 
				else 
				{
					// 如果返回值为正整数，则是实际写入缓冲区的字数，通知连接器实际写入的字
					// 数。连接器会自动进行判断是否还有数据需要处理。如果有数据待发，那么将
					// 继续调用设备的Send函数。
					// --------------------------------------------------------------------
					// 注意：EPoll 模型如果一次性发送大量的数据，在极小的概率下可能会导致线
					// 程的堆栈溢出（未测试，跟流量及系统的缓存有关，一般认为不要一次性发送
					// 大于100MB的数据。）。如果连接器没有开启连接的输出速度限制，那么，当输
					// 出的数据大大大于设备的发送速度时，设备与连接器之间反复的递归调用将导
					// 致线程堆栈的溢出。从而引起程序的崩溃。
					// --------------------------------------------------------------------
					// Windows下的完成端口和重叠IO并不会引起这种溢出，因为Windows下的IO模型
					// 是基于事件完成通知，因此，每一次发送或者接收后，线程都会结束当前操作，
					// 等待完成通知，并由完成端口线程处理余下的工作。因此，并不会发生类似于
					// EPoll模型的递归调用。
					result = true;
					CInterface<ITcpConnectorFlushDevice> segment;
					if( segment.Mount(connector, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
						segment -> OnDataSent( static_cast<size_t>(bytes) );
					}
				}
			}
		}

		if( result == false )
		{
			Report( connector, EID_CONNECTION_DISCONNECTED );
		}
	}
	return result;

	#else

	UNREFERENCED_PARAMETER( name   );
	UNREFERENCED_PARAMETER( data   );
	UNREFERENCED_PARAMETER( offset );
	UNREFERENCED_PARAMETER( length );
	return false;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Receive(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER(name);
	#ifdef __linux
	return true;
	#else
	return false;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Accept(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER(name);
	#ifdef __linux
	return true;
	#else
	return false;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CTcpEpollIOModelImplement::OnProcess(U32 index) 
{
    //TODO Auto-generated method stub
	#ifdef __linux

	if( index >= MAX_EPOLL_THREAD ) return -1;
		
	// 初始化要使用的变量。
	#define EVENT_COUNT 100
	epoll_event events[EVENT_COUNT];

	int  size = 0;
	bool lost = false;

	// 进入主循环，开始等待epoll的事件。
	for( ;; )
	{
		size = epoll_wait( epolls[index], events, EVENT_COUNT, 1000 );
		if( size == -1 ) 
		{
			if( errno == EINTR || errno == EAGAIN ) {
				continue;
			} else {
				printf("Occur error[%d][%s], epoll working thread exit...\n", errno, strerror(errno) );
				break;
			}
		}

		for( int i = 0; i < size; ++ i )
		{
			CObjectPtr object = Obtain( events[i].data.u64 );
			if( object )
			{
				// Check event category, is some error occur ?
				if( events[i].events & EPOLLERR ) {
					Report( object, EID_CONNECTION_DISCONNECTED );
					continue;
				}

				lost = false;
				if( events[i].events & EPOLLIN  )
				{
					object -> GetType() == OID_TCP_LISTENER ?
					lost = !OnAccept ( object ):
					lost = !OnReceive( object );
				}

				if( events[i].events & EPOLLOUT ) {
					lost = !OnSend   ( object );
				}

				// if disconnected, report event;
				if( lost ) {
					Report( object, EID_CONNECTION_DISCONNECTED );
				}
			}
		}

		// If io model is shutting down, stop thread.
		if( active == false ) break;
	}
	return 0;

	#else

	UNREFERENCED_PARAMETER( index );
	return 0;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpEpollIOModelImplement::GetAmount() 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	return amount;
	#else
	return 0;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpEpollIOModelImplement::PreShutdown() 
{
    //TODO Auto-generated method stub
	#ifdef __linux
	CInterface<IInstanceContainer> segment;
	if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
	{
		CU64Array indices;
		segment -> Obtain( indices );

		for( size_t i = 0, j = indices.size(); i < j; ++ i )
		{
			CObjectPtr object;
			object = segment -> Obtain( indices[i] );

			if( object ) {
				CInstanceUtility::ShutdownInstance( object );
				segment -> Remove( indices[i] );
			}
		}
	}

	active = false;
	#endif
}

#ifdef __linux

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::OnAccept(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( object )
	{
		CInterface<ITcpListenerController> segment;
		if( segment.Mount(object, IID_TCP_LISTENER_CONTROLLER) ) 
		{
			SOCKET hs = segment -> GetSocket();
			if( hs != INVALID_SOCKET )
			{
				sockaddr_in address;
				socklen_t length = static_cast<socklen_t>( sizeof(sockaddr_in) );

				int socket = accept( hs, reinterpret_cast<sockaddr*>(&address), & length );
				if( socket != INVALID_SOCKET )
				{
					int value;
					if( ( ( value = fcntl(socket, F_GETFL) ) == -1 ) ||
						( fcntl( socket, F_SETFL, value | O_NONBLOCK ) == -1 ) )
					{
						close( socket ); 
					} 
					else 
					{
						segment -> Accept( socket );
						result = true;
					}
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::OnReceive(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( object )
	{
		SOCKET hs = INVALID_SOCKET;
		CInterface<ITcpConnectionController> segment_1;
		if( segment_1.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
			hs = segment_1 -> GetSocket();
		}

		if( hs == INVALID_SOCKET ) return false;

		CMemory data;
		CInterface<IImportStream> segment_2;
		if( segment_2.Mount(object, IID_IMPORT_STREAM) ) 
		{
			bool received = false;
			for( ;; )
			{
				if( data.Alloc() == false ) {
					throw std::bad_alloc();
				}

				ssize_t retval = read( hs, data.Query<char>(), data.GetCapacity() );

				// 错误判断，如果返回值为0，则表示连接中断，返回-1，则表示有错误发生，
				// 如果错误为EAGAIN，则表示缓冲区已经取完，其他错误一律认为连接中断。
				if( retval ==  0 ) { result = false; break; }
				if( retval == -1 ) { result = (errno == EAGAIN); break; }

				// 如果成功的获取到数据，则将数据添加到连接器内。
				data.SetLength( static_cast<size_t>(retval) );

				// assign data to input stream;
				received = segment_2 -> Assign( data );

				// 只有当read或者write返回EAGAIN时才需要挂起，等待。但这并不是说每次
				// read时都需要循环读，直到读到产生一个EAGAIN才认为此次事件处理完成，
				// 当read返回的读到的数据长度小于请求的数据长度时，就可以确定此时缓冲
				// 中已没有数据了，也就可以认为此事读事件已处理完成。
				if( retval < static_cast<ssize_t>( data.GetCapacity() ) ) { 
					result = true; break; 
				} 
			}

			// report receive data event;
			if( result && received ) {
				Report( object, EID_CONNECTION_RECEIVE_DATA );
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::OnSend(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( object && amount && amount < MAX_EPOLL_THREAD )
	{
		SOCKET hs = INVALID_SOCKET;
		CInterface<ITcpConnectionController> segment_1;
		if( segment_1.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
			hs = segment_1 -> GetSocket();
		}

		if( hs != INVALID_SOCKET ) 
		{
			// 先更新fd的epoll监听事件，取消监听OUT事件；
			epoll_event ent;
			ent.data.u64 = object -> GetName();
			ent.events   = EPOLLIN | EPOLLET | EPOLLERR;
				
			// 为连接查找对应的epollset，并修改监听的事件；
			result = ( epoll_ctl( epolls[hs % amount], EPOLL_CTL_MOD, hs, & ent ) == 0 );
				
			// 继续发送未发送完毕的数据；
			if( result )
			{
				CInterface<ITcpConnectorFlushDevice> segment;
				if( segment.Mount(object, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
					segment -> OnDataSent( 0 );
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpEpollIOModelImplement::Report(CObjectPtr & connector, U32 eid) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( connector )
	{
		CInterface<IEventEmitter> segment;
		if( segment.Mount(connector, IID_EVENT_EMITTER) )
		{
			tagEvent msg;
			msg.handle = eid;
			msg.source = connector -> GetName();
			segment -> Report( msg );
		}
	}
	return result;
}

#endif

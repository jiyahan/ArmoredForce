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
			// if failed, close socket��
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
				// ����׼���õ�ַ�Ľṹ��
				sockaddr_in address;
				memset( & address, 0, sizeof(address) );

				address.sin_family      = AF_INET;
				address.sin_port        = htons( domain.port );
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );

				// �󶨸õ�ַ�ϵĸö˿ڸ�hs��
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
	
	// �ú������߼��̻߳����������߳��������ã����������ϣ��������������������
	// �����У���������������EPOLL�¼�������OUT�¼������¼�������ʱ����EPOLL�߳�
	// �����������δ�������������ݣ�����EPOLL�̸߳�������OUT��־��
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
					// �������-1����������Ϊд�뻺�����������µĴ��󷵻أ���ô��ʱ�Ͳ��ٽ�
					// ���κδ����������κ����飬����ȴ�EPoll��д�����֪ͨ�����������
					// ԭ���µĴ�����ô�ͱ�ʾ����ʧЧ��
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
					// �������ֵΪ������������ʵ��д�뻺������������֪ͨ������ʵ��д�����
					// �������������Զ������ж��Ƿ���������Ҫ������������ݴ�������ô��
					// ���������豸��Send������
					// --------------------------------------------------------------------
					// ע�⣺EPoll ģ�����һ���Է��ʹ��������ݣ��ڼ�С�ĸ����¿��ܻᵼ����
					// �̵Ķ�ջ�����δ���ԣ���������ϵͳ�Ļ����йأ�һ����Ϊ��Ҫһ���Է���
					// ����100MB�����ݡ��������������û�п������ӵ�����ٶ����ƣ���ô������
					// �������ݴ������豸�ķ����ٶ�ʱ���豸��������֮�䷴���ĵݹ���ý���
					// ���̶߳�ջ��������Ӷ��������ı�����
					// --------------------------------------------------------------------
					// Windows�µ���ɶ˿ں��ص�IO���������������������ΪWindows�µ�IOģ��
					// �ǻ����¼����֪ͨ����ˣ�ÿһ�η��ͻ��߽��պ��̶߳��������ǰ������
					// �ȴ����֪ͨ��������ɶ˿��̴߳������µĹ�������ˣ������ᷢ��������
					// EPollģ�͵ĵݹ���á�
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
		
	// ��ʼ��Ҫʹ�õı�����
	#define EVENT_COUNT 100
	epoll_event events[EVENT_COUNT];

	int  size = 0;
	bool lost = false;

	// ������ѭ������ʼ�ȴ�epoll���¼���
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

				// �����жϣ��������ֵΪ0�����ʾ�����жϣ�����-1�����ʾ�д�������
				// �������ΪEAGAIN�����ʾ�������Ѿ�ȡ�꣬��������һ����Ϊ�����жϡ�
				if( retval ==  0 ) { result = false; break; }
				if( retval == -1 ) { result = (errno == EAGAIN); break; }

				// ����ɹ��Ļ�ȡ�����ݣ���������ӵ��������ڡ�
				data.SetLength( static_cast<size_t>(retval) );

				// assign data to input stream;
				received = segment_2 -> Assign( data );

				// ֻ�е�read����write����EAGAINʱ����Ҫ���𣬵ȴ������Ⲣ����˵ÿ��
				// readʱ����Ҫѭ������ֱ����������һ��EAGAIN����Ϊ�˴��¼�������ɣ�
				// ��read���صĶ��������ݳ���С����������ݳ���ʱ���Ϳ���ȷ����ʱ����
				// ����û�������ˣ�Ҳ�Ϳ�����Ϊ���¶��¼��Ѵ�����ɡ�
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
			// �ȸ���fd��epoll�����¼���ȡ������OUT�¼���
			epoll_event ent;
			ent.data.u64 = object -> GetName();
			ent.events   = EPOLLIN | EPOLLET | EPOLLERR;
				
			// Ϊ���Ӳ��Ҷ�Ӧ��epollset�����޸ļ������¼���
			result = ( epoll_ctl( epolls[hs % amount], EPOLL_CTL_MOD, hs, & ent ) == 0 );
				
			// ��������δ������ϵ����ݣ�
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

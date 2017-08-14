#include "CTcpIocpIOModelImplement.h"
#include "utility/CSocketUtility.h"
#include "../system/CSystemInformation.h"
#include "../../utility/stl/CU32Array.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IEventEmitter.h"
#include "../../interface/IInstanceAliasContainer.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/ITcpConnectionController.h"
#include "../../interface/ITcpListenerController.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IImportStream.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
#define O_ACCEPT  1
#define O_RECEIVE 2
#define O_SEND    3



atom::CTcpIocpIOModelImplement::CTcpIocpIOModelImplement() : nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
#ifdef _WIN32
,size(1)
#endif
{
	#ifdef _WIN32
	memset( port, 0, sizeof(port) );
	#endif
}

atom::CTcpIocpIOModelImplement::~CTcpIocpIOModelImplement() 
{
}

int atom::CTcpIocpIOModelImplement::IncRef() 
{
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

int atom::CTcpIocpIOModelImplement::DecRef() 
{
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

int atom::CTcpIocpIOModelImplement::GetRef() 
{
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

atom::IInterface * atom::CTcpIocpIOModelImplement::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpIocpIOModelImplement::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

SOCKET atom::CTcpIocpIOModelImplement::Create() 
{
	#ifdef _WIN32
		return WSASocket( AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED );
	#else
		return INVALID_SOCKET;
	#endif
}

void atom::CTcpIocpIOModelImplement::Remove(SOCKET hs) 
{
	#ifdef _WIN32
		if( hs != INVALID_SOCKET ) closesocket( hs );
	#endif
}

bool atom::CTcpIocpIOModelImplement::Attach(U64 name) 
{
	if( !name ) return false;
	bool result = false;

	#ifdef _WIN32
	if( size && size <= MAX_IOCP_HANDLE )
	{
		CObjectPtr object = 
			CInstanceFactory::GetInstance() -> Inquire( name );
		if( object )
		{
			SOCKET socket = INVALID_SOCKET;
			CInterface<ITcpConnectionController> controller;
			if( controller.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
				socket = controller -> GetSocket();
			}

			if( INVALID_SOCKET != socket )
			{
				CInterface<IInstanceAliasContainer<SOCKET> > segment;
				if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) 
				{
					if( segment -> Insert(socket, object) )
					{
						result = ( NULL != 
							CreateIoCompletionPort( reinterpret_cast<HANDLE>(socket), 
							port[socket % size], socket, 0 ) );

						if( result == false ) {
							segment -> Remove( socket );
						}
					}
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	#endif

    return result;
}

bool atom::CTcpIocpIOModelImplement::Detach(U64 name) 
{
	bool result = false;

	#ifdef _WIN32
	if( name )
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
				CInterface<IInstanceAliasContainer<SOCKET> > segment;
				if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
					result = segment -> Remove( hs );
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	#endif

    return result;
}

atom::CObjectPtr atom::CTcpIocpIOModelImplement::Obtain(U64 name) 
{
	CObjectPtr result;
	#ifdef _WIN32
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

bool atom::CTcpIocpIOModelImplement::Initiate() 
{
	bool result = false;

	#ifdef _WIN32
	size = ( CSystemInformation::GetProcessorCount() + 3 ) / 2 * 2;
	size = atom_min( size, MAX_IOCP_HANDLE );
	size = atom_max( size, 1 );

	result = true;
	for( U32 i = 0; i < size && i < MAX_IOCP_HANDLE; ++ i ) 
	{
		if( NULL == ( port[i] = 
			CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0) ) ) {
			result = false;
		}
	}
	#endif

	return result;
}

bool atom::CTcpIocpIOModelImplement::Shutdown() 
{
	#ifdef _WIN32
	for( U32 i = 0; i < size && i < MAX_IOCP_HANDLE; ++ i ) 
	{
		if( port[i] ) {
			CloseHandle( port[i] ); port[i] = NULL;
		}
	}

	allocator.Shutdown();
	#endif

    return true;
}

bool atom::CTcpIocpIOModelImplement::Listen(U64 name, const tagDomain & domain) 
{
	bool result = false;
	
	#ifdef _WIN32
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

				address.sin_family			 = AF_INET;
				address.sin_port			 = htons( domain.port );
				address.sin_addr.S_un.S_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );

				// �󶨸õ�ַ�ϵĸö˿ڸ�hs��
				if( SOCKET_ERROR != 
					::bind( hs, reinterpret_cast<sockaddr*>(& address), 
					sizeof(sockaddr_in) ) ) {
					result = ( listen(hs, 256) != SOCKET_ERROR );
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	UNREFERENCED_PARAMETER( domain );
	#endif

	return result;
}

bool atom::CTcpIocpIOModelImplement::Connect(U64 name, const tagDomain & domain) 
{
	bool result = false;

	#ifdef _WIN32
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

				address.sin_family           = AF_INET;
				address.sin_port             = htons( domain.port );
				address.sin_addr.S_un.S_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );

				// connect to domain;
				result = ( 0 == connect( hs, 
					reinterpret_cast<sockaddr*>(& address), sizeof(sockaddr_in) ) );
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	UNREFERENCED_PARAMETER( domain );
	#endif

	return result;
}

bool atom::CTcpIocpIOModelImplement::Send(U64 name, CMemory & data, size_t offset, size_t length) 
{
	bool result = false;

	#ifdef _WIN32
	if( name && length && data.GetLength() >= offset + length )
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
				tagIocpOperation * packet = allocator.Allocate();
				if( packet )
				{
					packet -> op	 = O_SEND;
					packet -> wb.buf = data.Query<char>() + offset;
					packet -> wb.len = static_cast<ULONG>( length );
					packet -> mb     = data;
					packet -> Attach( connector );

					// �������ݣ����ʧ�ܣ�����սṹ�塣
					if( false == ( result = 
						OnSend(hs, & packet -> wb, & packet -> ol) ) ) 
					{
						packet -> Reset();
						allocator.Released( packet );
					}
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	UNREFERENCED_PARAMETER( data );
	UNREFERENCED_PARAMETER( offset );
	UNREFERENCED_PARAMETER( length );
	#endif

	return result;
}

bool atom::CTcpIocpIOModelImplement::Receive(U64 name) 
{
	bool result = false;
	#ifdef _WIN32
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
			tagIocpOperation * packet = allocator.Allocate();
			if( packet )
			{
				packet -> op = O_RECEIVE;
				if( packet -> mb.Alloc() )
				{
					packet -> wb.buf = packet -> mb.Query<char>();
					packet -> wb.len = static_cast<ULONG>( packet -> mb.GetCapacity() );
					packet -> Attach( connector );

					result = OnReceive( hs, & packet -> wb, & packet -> ol );
				}

				if( result == false )
				{
					packet -> Reset();
					allocator.Released( packet );
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	#endif

	return result;
}

bool atom::CTcpIocpIOModelImplement::Accept(U64 name) 
{
	bool result = false;

	#ifdef _WIN32
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
			tagIocpOperation * packet = allocator.Allocate();
			if( packet )
			{
				packet -> op = O_ACCEPT;
				if( packet -> mb.Alloc() )
				{
					packet -> hs     = Create();
					packet -> wb.buf = packet -> mb.Query<char>();
					packet -> wb.len = static_cast<ULONG>( packet -> mb.GetCapacity() );
					packet -> Attach( listener );

					result = OnAccept( hs, packet -> hs, & packet -> wb, & packet -> ol );
				}

				if( result == false ) 
				{
					packet -> Reset();
					allocator.Released( packet );
				}
			}
		}
	}
	#else
	UNREFERENCED_PARAMETER( name );
	#endif

	return result;
}

I32 atom::CTcpIocpIOModelImplement::OnProcess(U32 index) 
{
	I32 result = 0;

	#ifdef _WIN32
	if( size && size <= MAX_IOCP_HANDLE && index < size )
	{
		bool destory; tagIocpEvent ioe;

		for( ;; )
		{
			// �������ݵĳ�ʼֵ��
			destory = true; ioe.Reset();

			// ��ȡ��ɶ˿��ϵ��¼�
			if( GetCompletionEvent( index, & ioe, unsigned long(INFINITE) ) )
			{
				// �������ʱ��ioe.packet�ض���ֵ��
				switch( ioe.packet -> op )
				{
				case O_ACCEPT:
					destory = !OnAccept ( ioe.packet );
					ioe.losted = destory;
					break;
				case O_RECEIVE:
					destory = !OnReceive( ioe.length, ioe.packet );
					ioe.losted = destory;
					break;
				case O_SEND:
					ioe.losted = !OnSend( ioe.length, ioe.packet );
					break;
				}
			}

			// �������ID��0�����ʾ�˳��߳�
			if( ioe.object == 0 ) break;

			// ������Ӷ�ʧ����׼���ر����ӡ�
			if( ioe.losted )
			{
				CObjectPtr object;
				CInterface<IInstanceAliasContainer<SOCKET> > segment;
				if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
					object = segment -> Obtain( ioe.object );
				}

				if( object ) {
					Report( object, EID_CONNECTION_DISCONNECTED );
				}
			}

			// �����Ҫ����pPacket�ṹ��
			if( destory && ioe.packet ) {
				ioe.packet -> Reset(); allocator.Released( ioe.packet );
			}
		}
	}
	#endif

	return result;
}

U32 atom::CTcpIocpIOModelImplement::GetAmount()
{
	#ifdef _WIN32
	return size;
	#else
	return 0;
	#endif
}

void atom::CTcpIocpIOModelImplement::PreShutdown() 
{
	#ifdef _WIN32
	CInterface<IInstanceAliasContainer<SOCKET> > segment;
	if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
	{
		std::vector<SOCKET, atom_allocator<SOCKET> > indices;
		segment -> Obtain( indices );

		for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
			CObjectPtr object = segment -> Obtain( indices[i] );
			CInstanceUtility::ShutdownInstance( object );
		}

		segment -> RemoveAll();
	}

	// One port with two threads, post ratio times.
	for( U32 i = 0; i < size && i < MAX_IOCP_HANDLE; ++ i ) 
	{
		for( U32 j = 0; j < IOCP_TH_RATIO; ++ j ) {
			PostQueuedCompletionStatus( port[i], 0, 0, 0 );
		}
	}
	#endif
}

#ifdef _WIN32
bool atom::CTcpIocpIOModelImplement::OnAccept(tagIocpOperation * packet) 
{
	bool result = false;
	if( packet )
	{
		CObjectPtr listener = packet -> GetObject();
		if( listener )
		{
			SOCKET hs = INVALID_SOCKET;
			CInterface<ITcpConnectionController> segment;
			if( segment.Mount(listener, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = segment -> GetSocket();
			}

			if( hs != INVALID_SOCKET )
			{
				// Update client socket's context;
				setsockopt( packet -> hs, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT,  
					reinterpret_cast<CHAR*>(& hs), sizeof(SOCKET) );

				// Create connector;
				CInterface<ITcpListenerController> segment;
				if( segment.Mount(listener, IID_TCP_LISTENER_CONTROLLER) ) {
					segment -> Accept( packet -> hs );
				}

				// Resubmit quest;
				packet -> hs = Create();
				ZeroMemory( & packet -> ol, sizeof(OVERLAPPED) );
				result = OnAccept( hs, packet -> hs, & packet -> wb, & packet -> ol );
			}
		}
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::OnAccept(SOCKET listener, SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol) 
{
	bool result = false;
	DWORD bytes = 0;
	// AcceptEx���ĸ�����Ϊ0�����ʾ��������ʵ�����ڽ������ݵ��ڴ�������Ϊ0���Ӷ���ֹ
	// WinSock��Accept������ͬʱ�������Receive������ͬʱ���������ӵ���ʱ��Accept����
	// ��������ɣ�������ȴ��κ����ݡ�
	result = ( AcceptEx( listener, hs, wb -> buf, 0, 
		sizeof(SOCKADDR_IN) + 16, sizeof(SOCKADDR_IN) + 16, & bytes, ol ) == TRUE );
	if( result == false ) {
		result = ( WSAGetLastError() == WSA_IO_PENDING );
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::OnSend(size_t bytes, tagIocpOperation * packet) 
{
	bool result = false;
	if( bytes && packet )
	{
		CObjectPtr connector = packet -> GetObject();
		if( connector )
		{
			// write data finished
			result = true;
			CInterface<ITcpConnectorFlushDevice> segment;
			if( segment.Mount(connector, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
				segment -> OnDataSent( bytes );
			}
		}
	}
    return result;
}

bool atom::CTcpIocpIOModelImplement::OnSend(SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol) 
{
	bool result = false;
	DWORD bytes = 0;
	if( false == ( 
		result = ( WSASend(hs, wb, 1, & bytes, 0, ol, NULL) == 0 ) ) ) {
		result = ( WSAGetLastError() == WSA_IO_PENDING );
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::OnReceive(size_t bytes, tagIocpOperation * packet) 
{
	bool result = false;
	if( bytes && packet )
	{
		CObjectPtr connector = packet -> GetObject();
		if( connector )
		{
			SOCKET hs = INVALID_SOCKET;
			CInterface<ITcpConnectionController> segment;
			if( segment.Mount(connector, IID_TCP_CONNECTION_CONTROLLER) ) {
				hs = segment -> GetSocket();
			}

			if( hs != INVALID_SOCKET )
			{
				packet -> mb.SetLength( bytes );

				// assign data to input stream;
				CInterface<IImportStream> segment;
				if( segment.Mount(connector, IID_IMPORT_STREAM) ) {
					segment -> Assign( packet -> mb );
				}

				// report receive data event;
				Report( connector, EID_CONNECTION_RECEIVE_DATA );

				// resubmit receive quest
                if( packet -> mb.Alloc() )
				{
					packet -> wb.buf = packet -> mb.Query<char>();
					packet -> wb.len = static_cast<ULONG>( packet -> mb.GetCapacity() );

					ZeroMemory( & packet -> ol, sizeof(CIocpOverlap) );
					result = OnReceive( hs, & packet -> wb, & packet -> ol );
				}
			}
		}
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::OnReceive(SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol) 
{
	bool result = false;
	DWORD flag  = 0;
    DWORD byte  = 0; // �����������쳣����Ӱ��iocp�Ľ������ݣ�
	if( false == ( 
		result = ( WSARecv(hs, wb, 1, & byte, & flag, ol, NULL) == 0 ) ) ) {
		result = ( WSAGetLastError() == WSA_IO_PENDING ); 
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::GetCompletionEvent(U32 index, tagIocpEvent * ioe, U64 timeout) 
{
	bool result = false;
	if( ioe )
	{
		LPOVERLAPPED overlapped = NULL;
		if( GetQueuedCompletionStatus( 
			port[index], 
			& ioe -> length, 
			& ioe -> object, & overlapped, static_cast<DWORD>(timeout) ) )
		{
			if( overlapped ) 
			{
				// �������ʱ��overlapped�ض���ֵ�������һ��ָ��ļ��ֻ��
				// Ϊ��ȷ��ָ�����ȷ�ԡ�
				ioe -> packet = reinterpret_cast<tagIocpOperation *>( 
					CONTAINING_RECORD(overlapped, tagIocpOperation, ol) );

				// MSDN����������ɶ˿��������socket����ر�ʱ����ȡ��ɶ˿�״̬
				// �ĺ����᷵�سɹ���ͬʱoverlapped�ṹ�岻Ϊ�գ����⣬�ֽ�����Ϊ
				// 0����������������������������������������׽����ڽ��յ�accept
				// �¼�ʱ��ͬ���᷵���棬overlapped�ṹ�岻Ϊ�գ����⣬������ֽ�
				// ������0����ˣ����жϲ�Ϊ
				if( false == ( 
					ioe -> losted = (
					ioe -> length == 0 && 
					ioe -> packet -> op == O_RECEIVE) ) )
				{
					result = true;
				}
			}
		}
		else
		{
			if( overlapped )
			{
				// ���overlapped��Ϊ�գ�������ΪIO��ԭ�������û������ر�socket��
				// ���ӱ�����ֹ����ͬʱ����packet�ṹ�塣
				ioe -> packet = reinterpret_cast<tagIocpOperation *>( 
					CONTAINING_RECORD(overlapped, tagIocpOperation, ol) );
				ioe -> losted = true;
			}
			else
			{
				// ���overlappedΪ�գ����������Ϊ��ʱ��ԭ�������Ϊ��ʱ��
				// ����Ϊ������������ֹ��
				ioe -> losted = ( GetLastError() != WAIT_TIMEOUT );
			}
		}
	}
	return result;
}

bool atom::CTcpIocpIOModelImplement::Report(CObjectPtr & connector, U32 eid) 
{
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

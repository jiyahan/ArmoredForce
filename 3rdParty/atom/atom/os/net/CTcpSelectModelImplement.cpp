#include "CTcpSelectModelImplement.h"
#include "utility/CSocketUtility.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInstanceUtility.h"
#include "../../interface/IEventEmitter.h"
#include "../../interface/IInstanceContainer.h"
#include "../../interface/ITcpConnectionController.h"
#include "../../interface/ITcpListenerController.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IImportStream.h"
#include "../../enumeration/EVENT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../enumeration/OBJECT_ID.h"
//Begin section for file CTcpSelectModelImplement.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpSelectModelImplement.cpp
#ifdef _WIN32
#pragma warning( disable : 4127 ) // macro FD_SET rise this warning
#endif



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelImplement::CTcpSelectModelImplement() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
active(false),client_update(false),server_update(false)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpSelectModelImplement::~CTcpSelectModelImplement() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpSelectModelImplement::IncRef() 
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
int atom::CTcpSelectModelImplement::DecRef() 
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
int atom::CTcpSelectModelImplement::GetRef() 
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
atom::IInterface * atom::CTcpSelectModelImplement::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelImplement::SetNest(IInterface * value) 
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
SOCKET atom::CTcpSelectModelImplement::Create() 
{
    //TODO Auto-generated method stub
	return socket( AF_INET, SOCK_STREAM, 0 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelImplement::Remove(SOCKET hs) 
{
    //TODO Auto-generated method stub
    if( hs != INVALID_SOCKET ) 
	{
		#ifdef _WIN32
		closesocket( hs );
		#endif

		#ifdef __linux
		close( hs );
		#endif

		#ifdef __APPLE__
		close( hs );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Attach(U64 name) 
{
    //TODO Auto-generated method stub
	if( !name ) return false;
	bool result = false;

	CObjectPtr object = 
		CInstanceFactory::GetInstance() -> Inquire( name );
	if( object )
	{
		CInterface<ITcpConnectionController> controller;
		if( controller.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) 
		{
			if( INVALID_SOCKET != controller -> GetSocket() )
			{
				CInterface<IInstanceContainer> segment;
				if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
					result = segment -> Insert( object );
				}
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Detach(U64 name) 
{
    //TODO Auto-generated method stub
	bool result = false;
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

			bool succeeded = false;
			if( hs != INVALID_SOCKET )
			{
				if( object -> GetType() == OID_TCP_CONNECTOR )
				{
					succeeded = true;
					CCriticalSectionScope scope( region );
					client.erase( hs );
					client_update = true;
				}
				else
				if( object -> GetType() == OID_TCP_LISTENER  )
				{
					succeeded = true;
					CCriticalSectionScope scope( region );
					server.erase( hs );
					server_update = true;
				}
			}

			if( succeeded )
			{
				CInterface<IInstanceContainer> segment;
				if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
					result = segment -> Remove( name );
				}
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpSelectModelImplement::Obtain(U64 name) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	if( name )
	{
		CInterface<IInstanceContainer> segment;
		if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
			result = segment -> Obtain( name );
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Initiate() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Shutdown() 
{
    //TODO Auto-generated method stub
	bool result = false;
	CInterface<IInstanceContainer> segment;
	if( segment.Mount(this, IID_INSTANCE_CONTAINER) )
	{
		CU64Array indices;
		segment -> Obtain( indices );

		for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
			CObjectPtr object = segment -> Obtain( indices[i] );
			CInstanceUtility::ShutdownInstance( object );
		}

		segment -> RemoveAll();
		CCriticalSectionScope scope( region );

		sended.clear();
		server.clear();
		client.clear();
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Listen(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
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

				address.sin_family			 = AF_INET;
				address.sin_port			 = htons( domain.port );

				#ifdef _WIN32
				address.sin_addr.S_un.S_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				#ifdef __linux
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				#ifdef __APPLE__
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				// 绑定该地址上的该端口给hs。
				if( SOCKET_ERROR != 
					::bind( hs, reinterpret_cast<sockaddr*>(&address), 
					sizeof(sockaddr_in) ) ) {
					result = ( listen(hs, 5) != SOCKET_ERROR );
				}

				if( result )
				{
					CCriticalSectionScope scope( region );
					server.insert( make_pair(hs, name) );
					server_update = true;
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Connect(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
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

				address.sin_family = AF_INET;
				address.sin_port   = htons( domain.port );

				#ifdef _WIN32
				address.sin_addr.S_un.S_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				#ifdef __linux
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				#ifdef __APPLE__
				address.sin_addr.s_addr = CSocketUtility::DomainToIPV4( domain.host.c_str() );
				#endif

				// connect to domain;
				result = ( 0 == connect( hs, 
					reinterpret_cast<sockaddr*>(& address), sizeof(sockaddr_in) ) );
				if( result )
				{
					CCriticalSectionScope scope( region );
					client.insert( make_pair(hs, name) );
					client_update = true;
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Send(U64 name, CMemory & data, size_t offset, size_t length) 
{
    //TODO Auto-generated method stub
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
			if( segment -> GetSocket() != INVALID_SOCKET )
			{
				tagTcpSelectOperation op;
				op.target = name;
				op.socket = segment -> GetSocket();
				op.memory = data;
				op.offset = offset;
				op.length = length;
				op.serial = serial.Increase();
				result = true;

				// 将事件写入队列，并等待socket就绪，之后发送。
				region.Enter();
				sended.insert( op );
				region.Leave();
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Receive(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER(name);
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Accept(U64 name) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER(name);
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpSelectModelImplement::SetActive(bool value)
{
    //TODO Auto-generated method stub
	active = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CTcpSelectModelImplement::OnProcess() 
{
    //TODO Auto-generated method stub
	typedef vector<SOCKET, atom_allocator<SOCKET> > CSocketArray;
	
	// select模型是单线程模式，仅适合数据量不大的情况，比较适合客户端。兼容性较好；
	// 在select的执行线程内，每次都会轮询所有的数据，包括读，写，接收。
	unsigned int result = 0;

	fd_set queue;
	FD_ZERO( & queue );

	tagTcpSelectOperation::CTcpSelectOperationBind writed;
	CSocketArray readed;
	CSocketArray accept;
	CSocketArray stored;

	timeval tv;
	tv.tv_sec  = 0;
	tv.tv_usec = 0;

	U64 elapse(0); 
	CMilisecondTimer timer; 

	for(;;)
	{
		timer.Record();

		// 判断是否需要新数据；
		if( server_update )
		{
			accept.clear();

			region.Enter();
			std::transform( server.begin(), server.end(), back_inserter(accept),
				atom::select1st<CTcpSelectModelImplement::CTcpSelectModelSocketBind::value_type>() );
			server_update = false;
			region.Leave();

			std::sort( accept.begin(), accept.end() );
		}

		// 判断是否需要新数据；
		if( client_update )
		{
			readed.clear();

			region.Enter();
			std::transform( client.begin(), client.end(), back_inserter(readed),
				atom::select1st<CTcpSelectModelImplement::CTcpSelectModelSocketBind::value_type>() );
			client_update = false;
			region.Leave();

			std::sort( readed.begin(), readed.end() );
		}

		// 首先检查accept队列。
		stored.reserve( FD_SETSIZE );
		size_t time = ( accept.size() + FD_SETSIZE - 1 ) / FD_SETSIZE;

		// 首先执行accept操作；
		CSocketArray::iterator it = accept.begin();
		for( size_t i = 0; i < time; ++ i )
		{
			FD_ZERO( & queue ); stored.clear(); 
			SOCKET max_fd = static_cast<SOCKET>(-1);

			for( size_t j = 0; j < FD_SETSIZE && it != accept.end(); ++ j, ++ it ) 
			{
				max_fd = *it;
				stored.push_back( max_fd );
				FD_SET( max_fd, & queue );
			}

			int retval = select( static_cast<int>(max_fd + 1), & queue, NULL, NULL, & tv );
			if( retval == 0 ) {
				// time over, continue;
				continue;
			}
			else 
			if( retval <  0 ) {
				// some error occur;
				continue;
			}
			else
			if( retval >  0 ) 
			{
				// accept
				for( size_t m = 0, n = stored.size(); m < n; ++ m ) {
					if( FD_ISSET(stored[m], & queue) ) OnAccept( stored[m] );
				}
			}
		}

		// 然后执行read操作；
		it = readed.begin();
		time = ( readed.size() + FD_SETSIZE - 1 ) / FD_SETSIZE;

		for( size_t i = 0; i < time; ++ i )
		{
			FD_ZERO( & queue ); stored.clear(); 
			SOCKET max_fd = static_cast<SOCKET>(-1);

			for( size_t j = 0; j < FD_SETSIZE && it != readed.end(); ++ j, ++ it ) 
			{
				max_fd = *it;
				stored.push_back( max_fd );
				FD_SET( max_fd, & queue );
			}

			int retval = select( static_cast<int>(max_fd + 1), & queue, NULL, NULL, & tv );
			if( retval == 0 ) {
				// time over, continue;
				continue;
			}
			else 
			if( retval <  0 ) {
				// error occur;
				continue;
			}
			else
			if( retval >  0 ) 
			{
				// some socket ready for receive data
				for( size_t m = 0, n = stored.size(); m < n; ++ m ) {
					if( FD_ISSET(stored[m], & queue) ) OnReceive( stored[m] );
				}
			}
		}

		// 最后处理写
		region.Enter();
		if( sended.empty() ) 
		{
			// 如果队列为空，则计数器重置为0；
			serial.Assign( 0 );
		}
		else
		{
			// 交换数据；
			writed.swap( sended );
		}
		region.Leave();

		// 如果有值，则继续；
		if( !writed.empty() )
		{
			for( tagTcpSelectOperation::CTcpSelectOperationBind::
				iterator it = writed.begin(); it != writed.end(); )
			{
				FD_ZERO( & queue ); 
				FD_SET ( it -> socket, & queue );

				int retval = select( static_cast<int>(it -> socket + 1), NULL, & queue, NULL, & tv );
				if( retval == 0 ) {
					// still block time over, continue;
					++ it; continue;
				}
				else 
				if( retval <  0 ) {
					// bug;
					++ it; continue;
				}
				else
				if( retval >  0 ) 
				{
					OnSend( *it );
					SAFE_ERASE( writed, it );
				}
			}

			// 将余下的数据写回；
			region.Enter();
			for( tagTcpSelectOperation::CTcpSelectOperationBind::
				iterator it = writed.begin(); it != writed.end(); ++ it ) {
				sended.insert( *it );
			}
			region.Leave();
		}

		if( active == false ) break;

		writed.clear();
        elapse = timer.GetElapsedTime();
        if( elapse < 5 ) {
            CThread::Sleep( 5 - elapse );
        }
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpSelectModelImplement::ObtainBySocket(SOCKET hs) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	if( hs != INVALID_SOCKET )
	{
		U64 name = 0;

		region.Enter();
		{
			CTcpSelectModelSocketBind::iterator 
				it  = client.find( hs );
			if( it != client.end() ) {
				name = it -> second;
			}
		}

		if( name == 0 )
		{
			CTcpSelectModelSocketBind::iterator 
				it  = server.find( hs );
			if( it != server.end() ) {
				name = it -> second;
			}
		}
		region.Leave();

		if( name )
		{
			CInterface<IInstanceContainer> segment;
			if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
				result = segment -> Obtain( name );
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::OnAccept(SOCKET socket) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( socket != INVALID_SOCKET )
	{
		// 如果就绪，则获取相应的链接，并执行accept;
		CObjectPtr listener = ObtainBySocket( socket );
		if( listener )
		{
			SOCKET client_socket = ::accept( socket, NULL, NULL );
			if( client_socket != INVALID_SOCKET ) 
			{
				#ifdef __APPLE__
				int value = 1;
				setsockopt( socket, SOL_SOCKET, SO_NOSIGPIPE, & value, sizeof(int) );
				#endif

				U64 name = 0;
				CInterface<ITcpListenerController> segment;
				if( segment.Mount(listener, IID_TCP_LISTENER_CONTROLLER) ) {
					name = segment -> Accept( client_socket );
				}

				// open connector succeeded;
				if( name ) 
				{
					result = true;
					CCriticalSectionScope scope( region );
					client.insert( make_pair(client_socket, name) );
					client_update = true;
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::OnSend(const tagTcpSelectOperation & op) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( op.socket != INVALID_SOCKET )
	{
		CObjectPtr connector = Obtain( op.target );
		if( connector )
		{
			#ifdef _WIN32
			int retval = send( op.socket, 
				op.memory.Query<char>() + op.offset, static_cast<int>(op.length), 0 );
			#endif

			#ifdef __linux
			ssize_t retval = send( op.socket, 
				op.memory.Query<char>() + op.offset, static_cast<int>(op.length), MSG_NOSIGNAL );
			#endif

			#ifdef __APPLE__
			ssize_t retval = send( op.socket, 
				op.memory.Query<char>() + op.offset, static_cast<int>(op.length), 0 );
			#endif

			if( retval == 0 )
			{
				// what wrong ?
			}
			else 
			if( retval <  0 )
			{
				// error occur
				Report( connector, EID_CONNECTION_DISCONNECTED );
			}
			else
			if( retval >  0 )
			{
				// write data finished
				result = true;
				CInterface<ITcpConnectorFlushDevice> segment;
				if( segment.Mount(connector, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
					segment -> OnDataSent( static_cast<size_t>(retval) );
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::OnReceive(SOCKET socket) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( socket != INVALID_SOCKET )
	{
		// 准备执行读取操作；
		CObjectPtr connector = ObtainBySocket( socket );
		if( connector )
		{
			CMemory data; 
			if( data.Alloc() )
			{
				#ifdef _WIN32
				int retval = recv( socket, 
					data.Query<char>(), static_cast<int>( data.GetCapacity() ), 0 );
				#endif

				#ifdef __linux
				ssize_t retval = recv( socket, 
					data.Query<char>(), static_cast<int>( data.GetCapacity() ), 0 );
				#endif

				#ifdef __APPLE__
				ssize_t retval = recv( socket, 
					data.Query<char>(), static_cast<int>( data.GetCapacity() ), 0 );
				#endif

				if( retval == 0 )
				{
					// disconnected
					Report( connector, EID_CONNECTION_DISCONNECTED );
				}
				else 
				if( retval <  0 )
				{
					// error occur
					Report( connector, EID_CONNECTION_DISCONNECTED );
				}
				else
				if( retval >  0 )
				{
					// retval is data length;
					data.SetLength( static_cast<size_t>(retval) );

					// assign data to input stream;
					CInterface<IImportStream> segment;
					if( segment.Mount(connector, IID_IMPORT_STREAM) ) {
						result = segment -> Assign( data );
					}

					// report receive data event;
					Report( connector, EID_CONNECTION_RECEIVE_DATA );
				}
			}
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpSelectModelImplement::Report(CObjectPtr & connector, U32 eid)
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

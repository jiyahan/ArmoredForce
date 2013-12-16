#include "CTcpKQueueIOModelImplement.h"
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
//Begin section for file CTcpKQueueIOModelImplement.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpKQueueIOModelImplement.cpp



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueIOModelImplement::CTcpKQueueIOModelImplement() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
#ifdef __APPLE__
,size(1),active(false)
#endif
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	memset( port, 0, sizeof(port) );
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpKQueueIOModelImplement::~CTcpKQueueIOModelImplement() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpKQueueIOModelImplement::IncRef() 
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
int atom::CTcpKQueueIOModelImplement::DecRef() 
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
int atom::CTcpKQueueIOModelImplement::GetRef() 
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
atom::IInterface * atom::CTcpKQueueIOModelImplement::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueIOModelImplement::SetNest(IInterface * value) 
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
SOCKET atom::CTcpKQueueIOModelImplement::Create() 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	return socket( AF_INET, SOCK_STREAM, 0 );
	#else
	return INVALID_SOCKET;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueIOModelImplement::Remove(SOCKET hs) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	if( hs != INVALID_SOCKET ) {
		close( hs );
	}
	#else
	UNREFERENCED_PARAMETER( hs );
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Attach(U64 name) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	if( !name ) return false;
	bool result = false;

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
			CInterface<IInstanceAliasContainer<SOCKET> > segment;
			if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) 
			{
				if( segment -> Insert(hs, object) )
				{
					void * flag = (void *) object -> GetType();
					if( false == ( result = 
						Change( hs, EVFILT_READ,  EV_ADD, flag) ) ) {
						segment -> Remove( hs );
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
bool atom::CTcpKQueueIOModelImplement::Detach(U64 name) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__

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

			if( hs != INVALID_SOCKET )
			{
				CInterface<IInstanceAliasContainer<SOCKET> > segment;
				if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) 
				{
					result = segment -> Remove( hs );					
					Change( hs, EVFILT_READ, EV_DELETE, NULL );
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
atom::CObjectPtr atom::CTcpKQueueIOModelImplement::Obtain(U64 name) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	#ifdef __APPLE__
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
bool atom::CTcpKQueueIOModelImplement::Initiate() 
{
    //TODO Auto-generated method stub
	bool result = false;

	#ifdef __APPLE__
	result = true;
	size = static_cast<U32>( ( CSystemInformation::GetProcessorCount() + 3 ) / 2 * 2 );
	size = atom_max( size, 1 );
	size = atom_min( size, MAX_KQUEUE_THREAD );

	for( U32 i = 0; i < size; ++ i ) {
		result = ( ( port[i] = kqueue() ) != -1 ) && result;
	}
	
	active = result;
	#endif

	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Shutdown() 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	for( U32 i = 0; i < size; ++ i ) {
		if( port[i] == 0 || port[i] == -1 ) continue;
		close( port[i] );
	}

	memset( port, 0, sizeof(port) );
	allocator.Shutdown();
	#endif

    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Listen(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__

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
bool atom::CTcpKQueueIOModelImplement::Connect(U64 name, const tagDomain & domain) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__

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
bool atom::CTcpKQueueIOModelImplement::Send(U64 name, CMemory & data, size_t offset, size_t length) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
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
				tagTcpKQueueOperation * op = allocator.Allocate();
				if( op )
				{
					//op -> Attach( connector );
					op -> memory = data;
					op -> offset = offset;
					op -> length = length;

					result = Change( hs, EVFILT_WRITE, EV_ADD | EV_ONESHOT, op );

					if( result == false ) {
						op -> Reset(); allocator.Released( op );
					}
				}
			}
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
bool atom::CTcpKQueueIOModelImplement::Receive(U64 connector) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( connector );
	#ifdef __APPLE__
    return true;
	#else
	return false;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Accept(U64 listener) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( listener );
	#ifdef __APPLE__
    return true;
	#else
	return false;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CTcpKQueueIOModelImplement::OnProcess(U32 index) 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	
	if( index < size && port[index] > 0 )
	{
		const static timespec time = { 1, 0 };

		#define MAX_KEVENT 64
		struct kevent events[MAX_KEVENT];
		for( ;; )
		{
			int retval = kevent( port[index], NULL, 0, events, MAX_KEVENT, & time );
			if( retval == 0 || retval == -1 ) {
				continue;
			}

			for( int i = 0; i < retval; ++ i )
			{
				if( events[i].flags & EV_ERROR ) 
				{
					CObjectPtr object = ObtainBySocket( static_cast<SOCKET>(events[i].ident) );
					Report( object, EID_CONNECTION_DISCONNECTED );
					continue;
				}

				switch( events[i].filter )
				{
				case EVFILT_READ:
					if( (U64)events[i].udata == OID_TCP_LISTENER  ) {
						OnAccept ( & events[i] );
					}
					else
					if( (U64)events[i].udata == OID_TCP_CONNECTOR ) {
						OnReceive( & events[i] );
					}
					break;
				case EVFILT_WRITE: {
						OnSend   ( & events[i] );
					}
					break;
				}
			}
		}
	}
	return 0;
	
	#else

	UNREFERENCED_PARAMETER( index );
	return -1;

	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CTcpKQueueIOModelImplement::GetAmount() 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	return size;
	#else
	return 0;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpKQueueIOModelImplement::PreShutdown() 
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	CInterface<IInstanceAliasContainer<SOCKET> > segment;
	if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
	{
		std::vector<SOCKET, atom_allocator<SOCKET> > indices;
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

#ifdef __APPLE__
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CTcpKQueueIOModelImplement::ObtainBySocket(SOCKET socket) 
{
    //TODO Auto-generated method stub
	CObjectPtr result;
	if( socket != INVALID_SOCKET )
	{
		CInterface<IInstanceAliasContainer<SOCKET> > segment;
		if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
			result = segment -> Obtain( socket );
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Report(CObjectPtr & connector, U32 eid) 
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::Change(int hs, int filter, int flag, void * data)
{
    //TODO Auto-generated method stub
	#ifdef __APPLE__
	const static timespec time = { 0, 0 };
	struct kevent change[1]; 
	
	EV_SET( & change[0], hs, filter, flag, 0, 0, data ); 
	return( -1 != kevent( port[hs % size], change, 1, NULL, 0, & time ) );
	#else
    return false;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::OnAccept(CKQueueEvent * op) 
{
    //TODO Auto-generated method stub
	if( !op ) return false;

	SOCKET socket = static_cast<SOCKET>( op -> ident );
	if( socket == INVALID_SOCKET ) return false;

	bool result = false;
	CObjectPtr object = ObtainBySocket( socket );
	if( object )
	{
		CInterface<ITcpListenerController> segment;
		if( segment.Mount(object, IID_TCP_LISTENER_CONTROLLER) ) 
		{
			result = true;
			for( int i = 0, j = static_cast<int>(op -> data); i < j; ++ i )
			{
				SOCKET client_socket = ::accept( socket, NULL, NULL );
				if( client_socket != INVALID_SOCKET ) 
				{
					int value = 1;
					setsockopt( socket, SOL_SOCKET, SO_NOSIGPIPE, & value, sizeof(int) );
					segment -> Accept( client_socket );
				}
			}
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::OnSend(CKQueueEvent * value) 
{
    //TODO Auto-generated method stub
	if( !value ) return false;

	tagTcpKQueueOperation * op = 
		reinterpret_cast<tagTcpKQueueOperation *>( value -> udata );
	if( !op ) return false; 

	bool result = false;
	SOCKET socket = static_cast<SOCKET>( value -> ident );
	
	if( socket != INVALID_SOCKET )
	{
		CObjectPtr connector = ObtainBySocket( socket );
		if( connector )
		{
			int     length = static_cast<int>( op -> length );
					length = atom_min( length, static_cast<int>(value -> data) );
			ssize_t retval = send( socket, op -> memory.Query<char>() + op -> offset, length, 0 );

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

	op -> Reset();
	allocator.Released( op );
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpKQueueIOModelImplement::OnReceive(CKQueueEvent * op) 
{
    //TODO Auto-generated method stub
	if( !op ) return false;

	SOCKET socket = static_cast<SOCKET>( op -> ident );
	if( socket == INVALID_SOCKET ) return false;

	// 准备执行读取操作；
	bool result = false;
	CObjectPtr connector = ObtainBySocket( socket );
	if( connector )
	{
		CMemory data; 
		if( data.Alloc() )
		{
			ssize_t retval = recv( socket, 
				data.Query<char>(), static_cast<int>( data.GetCapacity() ), 0 );
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
	return result;
}

#endif

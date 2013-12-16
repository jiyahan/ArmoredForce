#include "CConnectionSchedulerController.h"
#include "../interface/IConnectorStubFrame.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/OBJECT_ID.h"
//Begin section for file CConnectionSchedulerController.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerController.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerController::CConnectionSchedulerController() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
amount(1),inner_space(0),outer_space(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectionSchedulerController::~CConnectionSchedulerController() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectionSchedulerController::IncRef() 
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
int electron::CConnectionSchedulerController::DecRef() 
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
int electron::CConnectionSchedulerController::GetRef() 
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
IInterface * electron::CConnectionSchedulerController::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerController::SetNest(IInterface * value) 
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
bool electron::CConnectionSchedulerController::Initiate() 
{
    //TODO Auto-generated method stub
    CInterface<IMultiThreadControl> segment_1;
    if( segment_1.Mount(this, IID_MULTI_THREAD_CONTROL) ) 
    {
        amount = segment_1 -> GetThreadAmount();
        amount = atom_min( amount, MAX_SCHEDULER_WORKER_THREAD );
        amount = atom_max( amount, 1 );
    }

    bool result = false;
    inner_space = CEventService::GetInstance() -> Create();
    outer_space = CEventService::GetInstance() -> Create();

    if( inner_space && outer_space )
    {
        bool step_1(false), step_2(false);

        // Bind outer event space with scheduler event emitter;
        CInterface<IEventEmitter> segment_2;
        if( segment_2.Mount(this, IID_EVENT_EMITTER) ) {
            step_1 = segment_2 -> Attach( outer_space );
        }

        CObjectPtr inner = CInstanceUtility::ObtainInstance( inner_space );
        if( inner )
        {
            CInterface<IEventSpaceController> segment_3;
            if( segment_3.Mount(inner, IID_EVENT_SPACE_CONTROLLER) )
            {
                CObjectPtr object = 
                    CInstanceUtility::MakeObject( nest );
                if( object ) {
                    step_2 = segment_3 -> Attach( object, "Scheduler" );
                }
            }
        }

        result = step_1 && step_2;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerController::Shutdown() 
{
    //TODO Auto-generated method stub
    CInterface<IInstanceAliasContainer<U64> > segment_0;
    if( segment_0.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
    {
        CU64Array indices;
        segment_0 -> Obtain( indices );
        for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
            Close( indices[i] );
        }

        indices.clear();
        listener.Obtain( indices );
        for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
            Close( indices[i] );
        }    
    }

    if( inner_space )
    {
        CObjectPtr inner = CInstanceUtility::ObtainInstance( inner_space );
        if( inner )
        {
            CInterface<IEventSpaceController> segment_2;
            if( segment_2.Mount(inner, IID_EVENT_SPACE_CONTROLLER) ) {
                segment_2 -> Detach( CInstanceUtility::GetInstanceName(nest) );
            }
        }

        CEventService::GetInstance() -> Remove( inner_space );
        inner_space = 0;
    }

    if( outer_space )
    {
        CInterface<IEventEmitter> segment_3;
        if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
            segment_3 -> Detach();
        }

        CEventService::GetInstance() -> Remove( outer_space );
        outer_space = 0;
    }

    listener.RemoveAll();
    for( size_t i = 0; i < amount; ++ i ) {
        connectors[i].Clear(); 
        disconnect[i].Clear();
    }
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerController::Retrieve(U32 index) 
{
    //TODO Auto-generated method stub
    if( index < amount )
    {
        U64 time = CMilisecondTimer::Now();

        CInterface<IInstanceAliasContainer<U64> > segment_1;
        if( segment_1.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
        {
            CU64Array indices;
            connectors[index].Obtain( indices, true );

            for( size_t i = 0, j = indices.size(); i < j; ++ i )
            {
                CObjectPtr object = segment_1 -> Obtain( indices[i] );
                if( object )
                {
                    CInterface<IConnectorStubFrame> segment_2;
                    if( segment_2.Mount(object, IID_CONNECTOR_STUB_FRAME) ) {
                        while( segment_2 -> Read(time) );
                    }
                }
            }

            indices.clear();
            disconnect[index].Obtain( indices, true );
            for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
                Close( indices[i] );
            }
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionSchedulerController::GetSpace() 
{
    //TODO Auto-generated method stub
    return outer_space;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionSchedulerController::Listen(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    if( address && port && io_model && message_queue )
    {
        CObjectPtr node = CInstanceUtility::CreateInstance( OID_TCP_LISTENER );
        if( node )
        {
            bool succeeded = false;
            CInterface<IEventEmitter> segment_1;
            if( segment_1.Mount(node, IID_EVENT_EMITTER) ) {
                succeeded = segment_1 -> Attach( inner_space );
            }

            if( succeeded )
            {
                succeeded = false; U64 name = node -> GetName(); 
                if( CSocketUtility::Open(node, address, port, io_model) ) {
                    succeeded = listener.Insert( name, message_queue );
                }

                if( succeeded ) result = name;
            }
        }

        if( !result ) {
            if( node ) CInstanceUtility::ShutdownInstance( node );
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectionSchedulerController::Connect(const char * address, U16 port, U32 io_model, U64 message_queue) 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    if( address && port && io_model && message_queue )
    {
        bool succeeded = false;
        CObjectPtr node = CInstanceUtility::CreateInstance( OID_TCP_CONNECTOR  );
        CObjectPtr stub = CInstanceUtility::CreateInstance( OID_CONNECTOR_STUB );
        if( node && stub )
        {
            U64 name = node -> GetName();

            CObjectPtr scheduler;
            scheduler = CInstanceUtility::MakeObject( nest );
            if( scheduler )
            {
                CInterface<IEventEmitter> segment_1;
                if( segment_1.Mount(stub, IID_EVENT_EMITTER) ) {
                    succeeded = segment_1 -> Attach( scheduler );
                }
            }

            CInterface<IConnectorStubFrame> segment_2;
            if( segment_2.Mount(stub, IID_CONNECTOR_STUB_FRAME) ) {
                succeeded = succeeded && segment_2 -> Open( name, message_queue );
            }
            
            if( succeeded )
            {
                // if succeeded, insert stub into alias container;
                succeeded = false;
                if( CSocketUtility::Open(node, address, port, io_model) ) 
                {
                    CInterface<IInstanceAliasContainer<U64> > segment_3;
                    if( segment_3.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) ) {
                        succeeded = segment_3 -> Insert( name, stub );
                    }
                }

                // if succeeded, add connector's message rectrieve event;
                if( succeeded ) 
                {
                    result = name;
                    connectors[name % amount].Insert( name ); 
                    CInstanceUtility::InitiateInstance( stub );
                }
            }
        }

        if( !result )
        {
            if( stub ) CInstanceUtility::ShutdownInstance( stub );
            if( node ) CInstanceUtility::ShutdownInstance( node );
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerController::Send(U64 connector, CMessage * message) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( connector && message )
    {
        CInterface<IInstanceAliasContainer<U64> > segment_1;
        if( segment_1.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
        {
            CObjectPtr object = segment_1 -> Obtain( connector );
            if( object )
            {
                CInterface<IConnectorStubFrame> segment_2;
                if( segment_2.Mount(object, IID_CONNECTOR_STUB_FRAME) ) {
                    result = segment_2 -> Send( message );
                }
            }
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerController::Close(U64 name) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( name )
    {
        CObjectPtr object = CInstanceUtility::ObtainInstance( name );
        if( object )
        {
            switch( object -> GetType() )
            {
            case OID_TCP_CONNECTOR:
                {
                    CInterface<IInstanceAliasContainer<U64> > segment;
                    if( segment.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
                    {
                        CObjectPtr stub = segment -> Obtain( name );
                        if( stub )
                        {
                            result = segment -> Remove( name );
                            CInstanceUtility::ShutdownInstance( stub );
                        }
                    }
                }
                break;
            case OID_TCP_LISTENER:
                {
                    result = listener.Remove( name );
                }
                break;
            }

            // if succeeded, shutdown connection;
            if( result ) CInstanceUtility::ShutdownInstance( object );
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerController::OnConnectionLose(U64 name) 
{
    //TODO Auto-generated method stub
    disconnect[name % amount].Insert( name );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectionSchedulerController::OnConnectionOpen(U64 l_name, U64 c_name) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( l_name && c_name )
    {
        CInterface<IInstanceAliasContainer<U64> > segment_1;
        if( segment_1.Mount(this, IID_INSTANCE_ALIAS_CONTAINER) )
        {
            U64 m_name = listener.Obtain( l_name );
            if( m_name && segment_1 -> Inside(c_name) == false )
            {
                CObjectPtr node = CInstanceUtility::ObtainInstance( c_name );
                CObjectPtr stub = CInstanceUtility::CreateInstance( OID_CONNECTOR_STUB );
                if( node && stub )
                {
					// attach stub's event emitter to scheduler directly
                    CObjectPtr scheduler;
                    scheduler = CInstanceUtility::MakeObject( nest );
                    if( scheduler )
                    {
                        CInterface<IEventEmitter> segment_2;
                        if( segment_2.Mount(stub, IID_EVENT_EMITTER) ) {
                            result = segment_2 -> Attach( scheduler );
                        }
                    }

                    // open stub, and attach connector's event emitter to connector stub;
                    CInterface<IConnectorStubFrame> segment_3;
                    if( segment_3.Mount(stub, IID_CONNECTOR_STUB_FRAME) ) {
                        result = result && segment_3 -> Open( c_name, m_name );
                    }

                    // if succeeded, insert stub into alias container;
                    if( result ) {
                        result = segment_1 -> Insert( c_name, stub );
                    }

                    // if succeeded, add connector's message rectrieve event;
                    if( result ) {
                        connectors[c_name % amount].Insert( c_name );
                        CInstanceUtility::InitiateInstance( stub );
                    }
                }

                // if prior operations failed, shutdown connector stub and connector.
                if( result == false )
                {
                    if( stub ) CInstanceUtility::ShutdownInstance( stub );
                    if( node ) CInstanceUtility::ShutdownInstance( node );
                }
            }
        }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectionSchedulerController::OnReceive(U64 name) 
{
    //TODO Auto-generated method stub
    U32 index = name % amount; 
    connectors[index].Insert( name );

    CInterface<IMultiThreadControl> segment;
    if( segment.Mount(this, IID_MULTI_THREAD_CONTROL) ) {
        segment -> OnAwake( index );
    }
}

#include "CConnectorStubHeartBeat.h"
#include "../interface/IConnectorStubFrame.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/MESSAGE_ID.h"
#include "../enumeration/EVENT_ID.h"
//Begin section for file CConnectorStubHeartBeat.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectorStubHeartBeat.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubHeartBeat::CConnectorStubHeartBeat() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
count(0),doing(false)
{
    //TODO Auto-generated method stub
    timer.Record();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubHeartBeat::~CConnectorStubHeartBeat() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectorStubHeartBeat::IncRef() 
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
int electron::CConnectorStubHeartBeat::DecRef() 
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
int electron::CConnectorStubHeartBeat::GetRef() 
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
IInterface * electron::CConnectorStubHeartBeat::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubHeartBeat::SetNest(IInterface * value) 
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
void electron::CConnectorStubHeartBeat::OnMessage(CMessage * message) 
{
    //TODO Auto-generated method stub
    if( message )
    {
        CInterface<IConnectorStubFrame> segment;
        if( segment.Mount(this, IID_CONNECTOR_STUB_FRAME) )
        {
            U16 command = message -> GetCommandID();
            if( command == MID_HEART_BEAT_REQUEST )
            {
                CMessage respond( MID_HEART_BEAT_RESPOND );
                respond.Write( message -> ReadU32() );
                segment -> Send( & respond );
            }
            else
            if( command == MID_HEART_BEAT_RESPOND )
            {
                doing = doing && ( count != message -> ReadU32() );
            }
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 electron::CConnectorStubHeartBeat::OnProcess(U64 now) 
{
    //TODO Auto-generated method stub
    U64 result = U64(INFINITE);
    CInterface<IConnectorStubFrame> segment;
    if( segment.Mount(this, IID_CONNECTOR_STUB_FRAME) )
    {
	    // In heart beat check progress ?
	    if( doing == false )
	    {
            // Verify does this connector need heart beat check
            U64 lasted = segment -> LastReceive();
            if( now >= lasted + HEART_BEAT_INTERVAL )
            {
                doing  = true; timer.Record();
                result = now + 1000;

                CMessage msg( MID_HEART_BEAT_REQUEST );
			    msg.Write( ++ count );
                segment -> Send( & msg );
            }
            else
            {
                // next awaken time
                result = lasted + HEART_BEAT_INTERVAL;
            }
	    }
	    else
	    {
		    // Now in heart beat check progress, check does this 
            // progress timeout.
            if( now >=  HEART_BEAT_TIMEOUT )
		    {
                // Time out, peer not respond heart beat check.
                CInterface<IEventEmitter> emitter;
                if( emitter.Mount(this, IID_EVENT_EMITTER) )
                {
                    tagEvent value;
                    value.handle = EID_HEART_BEAT_DETECTION_FAILED;
                    value.source = CInstanceUtility::GetInstanceName( nest );
                    emitter -> Report( value );
                }
		    }
            else
            {
                // Not receive respond message now, check it later.
                result = now + 1000;

                // Send heart beat check message again;
                CMessage msg( MID_HEART_BEAT_REQUEST );
			    msg.Write( count );
                segment -> Send( & msg );
            }
	    }
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubHeartBeat::Reset() 
{
    //TODO Auto-generated method stub
    doing = false;
    count = 0;
    timer.Record();
}

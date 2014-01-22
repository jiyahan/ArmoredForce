#include "CConnectorStubHeartBeat.h"
#include "../interface/IConnectorStubFrame.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/MESSAGE_ID.h"
#include "../enumeration/EVENT_ID.h"


electron::CConnectorStubHeartBeat::CConnectorStubHeartBeat() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
count(0),doing(false)
{
    timer.Record();
}

electron::CConnectorStubHeartBeat::~CConnectorStubHeartBeat() 
{
}

int electron::CConnectorStubHeartBeat::IncRef() 
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

int electron::CConnectorStubHeartBeat::DecRef() 
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

int electron::CConnectorStubHeartBeat::GetRef() 
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

IInterface * electron::CConnectorStubHeartBeat::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubHeartBeat::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void electron::CConnectorStubHeartBeat::OnMessage(CMessage * message) 
{
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

U64 electron::CConnectorStubHeartBeat::OnProcess(U64 now) 
{
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

void electron::CConnectorStubHeartBeat::Reset() 
{
    doing = false;
    count = 0;
    timer.Record();
}

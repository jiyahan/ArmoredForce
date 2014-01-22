#include "CConnectorStubStatistics.h"


electron::CConnectorStubStatistics::CConnectorStubStatistics() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
large(0)
{
}

electron::CConnectorStubStatistics::~CConnectorStubStatistics() 
{
}

int electron::CConnectorStubStatistics::IncRef() 
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

int electron::CConnectorStubStatistics::DecRef() 
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

int electron::CConnectorStubStatistics::GetRef() 
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

IInterface * electron::CConnectorStubStatistics::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CConnectorStubStatistics::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void electron::CConnectorStubStatistics::OnReadFrame(U64 origin, U64 reduce) 
{
    CCriticalSectionScope scope( section );
    plain.read_bytes += origin;
    final.read_bytes += reduce;
    plain.read_frame += 1;
    final.read_frame += 1;
}

void electron::CConnectorStubStatistics::OnSendFrame(U64 origin, U64 reduce) 
{
    CCriticalSectionScope scope( section );
    plain.send_bytes += origin;
    final.send_bytes += reduce;
    plain.send_frame += 1;
    final.send_frame += 1;
}

void electron::CConnectorStubStatistics::OnLongFrame(U64 value) 
{
    CCriticalSectionScope scope( section );
    large = atom_max( large, value );
}

void electron::CConnectorStubStatistics::GetStatistics(U64 & l, tagFlowStatistics & p, tagFlowStatistics & f) 
{
    CCriticalSectionScope scope( section );
    l = large;
    p = plain;
    f = final;
}

void electron::CConnectorStubStatistics::Reset() 
{
    CCriticalSectionScope scope( section );
    large            = 0;
    plain.read_bytes = 0;
    plain.read_frame = 0;
    plain.send_bytes = 0;
    plain.send_frame = 0;
    final.read_bytes = 0;
    final.read_frame = 0;
    final.send_bytes = 0;
    final.send_frame = 0;
}

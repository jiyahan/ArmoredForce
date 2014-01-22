#include "CMessageLife.h"
#include "../interface/IMessageEntry.h"
#include "../enumeration/INTERFACE_ID.h"


electron::CMessageLife::CMessageLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

electron::CMessageLife::~CMessageLife() 
{
}

int electron::CMessageLife::IncRef() 
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

int electron::CMessageLife::DecRef() 
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

int electron::CMessageLife::GetRef() 
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

IInterface * electron::CMessageLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CMessageLife::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool electron::CMessageLife::Initiate() 
{
    return true;
}

bool electron::CMessageLife::Shutdown() 
{
    CInterface<IMessageEntry> segment_1;
    if( segment_1.Mount(this, IID_MESSAGE_ENTRY) ) {
        segment_1 -> Clear();
    }

    CInterface<IStream> segment_2;
    if( segment_2.Mount(this, IID_STREAM) ) {
        segment_2 -> Reset();
    }
    return true;
}

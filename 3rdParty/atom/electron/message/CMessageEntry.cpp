#include "CMessageEntry.h"
#include "../enumeration/MESSAGE_ID.h"


electron::CMessageEntry::CMessageEntry() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
command(MID_UNKNOW),connect(0)
{
}

electron::CMessageEntry::~CMessageEntry() 
{
}

int electron::CMessageEntry::IncRef() 
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

int electron::CMessageEntry::DecRef() 
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

int electron::CMessageEntry::GetRef() 
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

IInterface * electron::CMessageEntry::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void electron::CMessageEntry::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void electron::CMessageEntry::SetCommandID(U16 value) 
{
    command = value;
}

U16 electron::CMessageEntry::GetCommandID() 
{
    return command;
}

void electron::CMessageEntry::SetConnector(U64 value) 
{
    connect = value;
}

U64 electron::CMessageEntry::GetConnector() 
{
    return connect;
}

void electron::CMessageEntry::Clear() 
{
    command = MID_UNKNOW;
    connect = 0;
}

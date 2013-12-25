#include "CClientEventHandle.h"


CClientEventHandle::CClientEventHandle() 
{
	receiver.SetNest( this );
	this->SetName(9999);
}


CClientEventHandle::~CClientEventHandle() 
{
}


const char * CClientEventHandle::ToString() 
{
	static char name[] = "Simple Event Handle";
    return name;
}


atom::IInterface * CClientEventHandle::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
	case IID_EVENT_RECEIVER:
		if( receiver.IncRef() )
			result = & receiver;
        break;
	}
	return result;
}

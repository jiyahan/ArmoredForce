#include "StdAfx.h"
#include "CClientEventHandle.h"



CClientEventHandle::CClientEventHandle() 
{
	receiver_.SetNest( this );
	this->SetName(9999);
}


CClientEventHandle::~CClientEventHandle() 
{
}


const char * CClientEventHandle::ToString() 
{
	const static char name[] = "Simple Event Handle";
    return name;
}


atom::IInterface* CClientEventHandle::QueryInterface(U32 iid) 
{
    IInterface* result = NULL;
    switch( iid )
    {
	case IID_EVENT_RECEIVER:
		if( receiver_.IncRef() )
			result = &receiver_;
        break;
	}
	return result;
}

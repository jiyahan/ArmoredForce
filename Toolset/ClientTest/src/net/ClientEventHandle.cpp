#include "ClientEventHandle.h"


ClientEventHandle::ClientEventHandle() 
{
    receiver.SetNest( this );
    this->SetName(9999);
}


ClientEventHandle::~ClientEventHandle() 
{
}


const char * ClientEventHandle::ToString() 
{
    static char name[] = "Simple Event Handle";
    return name;
}


atom::IInterface * ClientEventHandle::QueryInterface(U32 iid) 
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

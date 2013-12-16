#include "StdAfx.h"
#include "CClientEventHandleReceiver.h"



using namespace atom;
using namespace electron;

CClientEventHandleReceiver::CClientEventHandleReceiver() 
    : nest(NULL)
{  
}


CClientEventHandleReceiver::~CClientEventHandleReceiver() 
{
}


int CClientEventHandleReceiver::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}


int CClientEventHandleReceiver::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}


int CClientEventHandleReceiver::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}


IInterface * CClientEventHandleReceiver::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}


void CClientEventHandleReceiver::SetNest(IInterface * value) 
{
    if( value ) 
        nest = value;
}


bool CClientEventHandleReceiver::OnEvent(const tagEvent & eh) 
{
	switch( eh.handle )
	{
	case EID_CONNECTION_CLOSED:
		{
			printf( "connection[%llu] closed.\n", eh.source );
		}
		break;
	case EID_CONNECTION_DISCONNECTED:
		{
			printf( "connection[%llu] disconnected.\n", eh.source );
			CObjectPtr object = CInstanceUtility::ObtainInstance( eh.source );
			if( object ) {
				CInstanceUtility::ShutdownInstance( object );
			}
		}
		break;
	case EID_CONNECTION_ESTABLISHED:
		{
			printf( "listener[%llu] report: new connector[%llu] established.\n", 
				eh.source, static_cast<U64>(eh.append) );
			printf( "connection[%llu] receive data.\n", eh.source );
			CObjectPtr object = CInstanceUtility::ObtainInstance( eh.source );
			if( object ) 
			{
			}
			
		}
		break;
	case EID_CONNECTION_READY:
		{
			printf( "connection[%llu] ready.\n", eh.source );
			//·¢ËÍÏûÏ¢
			//CMessage msg(ATG_RegistGateServer);
			//GateWorld::GetInstance()->GetSocketClient()->Send(msg);
		}
		break;
	case EID_CONNECTION_RECEIVE_DATA:
		{
			printf( "connection[%llu] receive data.\n", eh.source );
			CObjectPtr object = CInstanceUtility::ObtainInstance( eh.source );
			if( object ) 
			{
				CInterface<IImportStream> segment;
				if( segment.Mount(object, IID_IMPORT_STREAM) )
				{
					printf( "Msg: " );
					while( segment -> Available() ) 
					{
						char value = segment -> Read();
						printf( "%c", value );
					}
					printf( "\n" );
				}
			}
		}
		break;
	}
    return true;
}

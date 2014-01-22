#include "CTcpConnectorLife.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/ITcpConnectorController.h"
#include "../../interface/IEventEmitter.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"


atom::CTcpConnectorLife::CTcpConnectorLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CTcpConnectorLife::~CTcpConnectorLife() 
{
}

int atom::CTcpConnectorLife::IncRef() 
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

int atom::CTcpConnectorLife::DecRef() 
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

int atom::CTcpConnectorLife::GetRef() 
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

atom::IInterface * atom::CTcpConnectorLife::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CTcpConnectorLife::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

bool atom::CTcpConnectorLife::Initiate() 
{
    return true;
}

bool atom::CTcpConnectorLife::Shutdown() 
{
	CInterface<ITcpConnectorController> segment_1;
	if( segment_1.Mount(this, IID_TCP_CONNECTOR_CONTROLLER) ) {
		segment_1 -> Shut();
	}

	CInterface<ITcpConnectorFlushDevice> segment_2;
	if( segment_2.Mount(this, IID_TCP_CONNECTOR_FLUSH_DEVICE) ) {
		segment_2 -> Reset();
	}

	CInterface<IEventEmitter> segment_3;
	if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
		segment_3 -> Detach();
	}

	CInterface<IImportStream> segment_4;
	if( segment_4.Mount(this, IID_IMPORT_STREAM) ) {
		segment_4 -> Close();
	}

	CInterface<IExportStream> segment_5;
	if( segment_5.Mount(this, IID_EXPORT_STREAM) ) {
		segment_5 -> Close();
	}
	return true;
}

#include "CTcpConnectorLife.h"
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/ITcpConnectorController.h"
#include "../../interface/IEventEmitter.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CTcpConnectorLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorLife::CTcpConnectorLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CTcpConnectorLife::~CTcpConnectorLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CTcpConnectorLife::IncRef() 
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
int atom::CTcpConnectorLife::DecRef() 
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
int atom::CTcpConnectorLife::GetRef() 
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
atom::IInterface * atom::CTcpConnectorLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CTcpConnectorLife::SetNest(IInterface * value) 
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
bool atom::CTcpConnectorLife::Initiate() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CTcpConnectorLife::Shutdown() 
{
    //TODO Auto-generated method stub
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

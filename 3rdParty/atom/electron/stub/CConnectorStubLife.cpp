#include "CConnectorStubLife.h"
#include "../interface/IConnectorStubStatistics.h"
#include "../interface/IConnectorStubFrame.h"
#include "../interface/IConnectorStubHeartBeat.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CConnectorStubLife.cpp
//TODO: Add definitions that you want preserved
//End section for file CConnectorStubLife.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubLife::CConnectorStubLife() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CConnectorStubLife::~CConnectorStubLife() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int electron::CConnectorStubLife::IncRef() 
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
int electron::CConnectorStubLife::DecRef() 
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
int electron::CConnectorStubLife::GetRef() 
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
IInterface * electron::CConnectorStubLife::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CConnectorStubLife::SetNest(IInterface * value) 
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
bool electron::CConnectorStubLife::Initiate() 
{
    //TODO Auto-generated method stub
    if( nest )
    {
	    CObjectPtr object;
        object = CInstanceUtility::MakeObject( nest );
        if( object ) {
            CMaintainer::GetInstance() -> Attach( object );
        }
    }
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CConnectorStubLife::Shutdown() 
{
    //TODO Auto-generated method stub
    if( nest )
    {
        CMaintainer::GetInstance() -> Detach(
            CInstanceUtility::GetInstanceName(nest) );

        CInterface<IConnectorStubHeartBeat> segment_1;
        if( segment_1.Mount(this, IID_CONNECTOR_STUB_HEART_BEAT) ) {
            segment_1 -> Reset();
        }

        CInterface<IConnectorStubFrame> segment_2;
        if( segment_2.Mount(this, IID_CONNECTOR_STUB_FRAME) ) {
            segment_2 -> Shut();
        }

        CInterface<IEventEmitter> segment_3;
        if( segment_3.Mount(this, IID_EVENT_EMITTER) ) {
            segment_3 -> Detach();
        }

        CInterface<IConnectorStubStatistics> segment_4;
        if( segment_4.Mount(this, IID_CONNECTOR_STUB_STATISTICS) ) {
            segment_4 -> Reset();
        }
    }
    return true;
}

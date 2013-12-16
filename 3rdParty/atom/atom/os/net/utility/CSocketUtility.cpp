#include "CSocketUtility.h"
#include "../../../interface/ITcpConnectorFlushDevice.h"
#include "../../../interface/ITcpConnectorController.h"
#include "../../../interface/IEventEmitter.h"
#include "../../../interface/IImportStream.h"
#include "../../../interface/IExportStream.h"
#include "../../../enumeration/INTERFACE_ID.h"
#include "../../../utility/tool/CInterface.h"
#include "../../../utility/tool/CInstanceUtility.h"
//Begin section for file CSocketUtility.cpp
//TODO: Add definitions that you want preserved
//End section for file CSocketUtility.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CSocketUtility::DomainToIPV4(const char * address) 
{
    //TODO Auto-generated method stub
	U32 result = INADDR_NONE;
	if( address )
	{
		result = inet_addr( address );
		if( result == INADDR_NONE )
		{
			hostent * hostEnt = NULL;				
			if( ( hostEnt = gethostbyname(address) ) != NULL ) {
				memcpy( &result, hostEnt -> h_addr_list[0], hostEnt -> h_length );
			}
		}
	}
	return result;    
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CSocketUtility::Open(CObjectPtr & object, const char * host, U16 port, U32 io_model) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( object && host && port && io_model )
	{
		CInterface<ITcpConnectionController> segment;
		if( segment.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
			result = segment -> Open( host, port, io_model );
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CSocketUtility::Shut(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	CInstanceUtility::ShutdownInstance( object );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CSocketUtility::GetSelfAddress(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	a_string result;
	if( object )
	{
		CInterface<ITcpConnectionController> segment;
		if( segment.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
			result = segment -> GetSelfAddress();
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CSocketUtility::GetSelfPort(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	U16 result(0);
	if( object )
	{
		CInterface<ITcpConnectionController> segment;
		if( segment.Mount(object, IID_TCP_CONNECTION_CONTROLLER) ) {
			result = segment -> GetSelfPort();
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::a_string atom::CSocketUtility::GetPeerAddress(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	a_string result;
	if( object )
	{
		CInterface<ITcpConnectorController> segment;
		if( segment.Mount(object, IID_TCP_CONNECTOR_CONTROLLER) ) {
			result = segment -> GetPeerAddress();
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CSocketUtility::GetPeerPort(CObjectPtr & object) 
{
    //TODO Auto-generated method stub
	U16 result(0);
	if( object )
	{
		CInterface<ITcpConnectorController> segment;
		if( segment.Mount(object, IID_TCP_CONNECTOR_CONTROLLER) ) {
			result = segment -> GetPeerPort();
		}
	}
	return result;
}

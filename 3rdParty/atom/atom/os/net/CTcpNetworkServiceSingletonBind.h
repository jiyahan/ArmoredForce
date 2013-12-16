#ifndef CTCPNETWORKSERVICESINGLETONBIND_H
#define CTCPNETWORKSERVICESINGLETONBIND_H
//Begin section for file CTcpNetworkServiceSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CTcpNetworkServiceSingletonBind.h
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{



	class CTcpNetworkService;
	typedef CSingleton<CTcpNetworkService> CTcpNetworkServiceSingletonBind;



} //end namespace atom



#endif

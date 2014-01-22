#ifndef CTCPNETWORKSERVICESINGLETONBIND_H
#define CTCPNETWORKSERVICESINGLETONBIND_H
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{



	class CTcpNetworkService;
	typedef CSingleton<CTcpNetworkService> CTcpNetworkServiceSingletonBind;



} //end namespace atom



#endif

#ifndef ITCPNETWORKSERVICECONTROLLER_H
#define ITCPNETWORKSERVICECONTROLLER_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	class ITcpNetworkServiceController : public IEmbedInterface
	{




		public:

			virtual bool Initiate() = 0; 



			virtual bool Shutdown() = 0; 



			virtual CObjectPtr GetModel(U32 io_model) = 0; 



	};  //end class ITcpNetworkServiceController



} //end namespace atom



#endif

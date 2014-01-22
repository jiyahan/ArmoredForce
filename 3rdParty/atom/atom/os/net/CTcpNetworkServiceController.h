#ifndef CTCPNETWORKSERVICECONTROLLER_H
#define CTCPNETWORKSERVICECONTROLLER_H
#include "../../interface/ITcpNetworkServiceController.h"
#include "../../interface/IInterface.h"
#include "CTcpNetworkServiceControllerBind.h"
#include "../thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CTcpNetworkServiceController : public ITcpNetworkServiceController
	{


		private:


			IInterface * nest;



			CTcpNetworkServiceControllerBind mapping;



			CCriticalSection section;




		public:

			CTcpNetworkServiceController(); 



			virtual ~CTcpNetworkServiceController(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



			virtual CObjectPtr GetModel(U32 io_model); 



	};  //end class CTcpNetworkServiceController



} //end namespace atom



#endif

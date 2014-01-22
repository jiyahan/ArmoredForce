#ifndef CTCPNETWORKSERVICE_H
#define CTCPNETWORKSERVICE_H
#include "../../interface/IReferencedObject.h"
#include "CTcpNetworkServiceSingletonBind.h"
#include "../../pattern/container/CInstanceContainer.h"
#include "../../pattern/container/CInstanceContainerListener.h"
#include "CTcpNetworkServiceLife.h"
#include "CTcpNetworkServiceController.h"
#include "../thread/CReference.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CTcpNetworkService : public IReferencedObject, public CTcpNetworkServiceSingletonBind
	{


		private:


			CInstanceContainer container;



			CInstanceContainerListener listener;



			CTcpNetworkServiceLife life;



			CTcpNetworkServiceController controller;



			U32 type;



			U64 name;



			CReference lock;




		public:

			CTcpNetworkService(); 



			virtual ~CTcpNetworkService(); 



			virtual void SetName(U64 name); 



			virtual U64 GetName(); 



			virtual void SetType(U32 type); 



			virtual U32 GetType(); 



			virtual const char * ToString(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			bool Initiate(); 



			bool Shutdown(); 



			CObjectPtr GetModel(U32 io_model); 



	};  //end class CTcpNetworkService



} //end namespace atom



#endif

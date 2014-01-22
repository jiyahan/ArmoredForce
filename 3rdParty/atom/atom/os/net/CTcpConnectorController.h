#ifndef CTCPCONNECTORCONTROLLER_H
#define CTCPCONNECTORCONTROLLER_H
#include "../../interface/ITcpConnectorController.h"
#include "../../interface/IInterface.h"
#include "tagDomain.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



	class CTcpConnectorController : public ITcpConnectorController
	{


		private:


			IInterface * nest;


			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			bool active;



			U32 iomold;



			SOCKET socket;



			tagDomain domain;



			tagDomain remote;



			CCriticalSection region;



			void Update(); 




		public:

			CTcpConnectorController(); 



			virtual ~CTcpConnectorController(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Open(const char * address, U16 port, U32 io_model); 



			virtual bool Open(SOCKET socket, U32 io_model); 



			virtual void Shut(); 



			//<p>Is connection active ?</p>
			virtual bool GetActive(); 



			//<p>Get connection's socket</p>
			virtual SOCKET GetSocket(); 



			//<p>Get connection's IO model's name</p>
			virtual U32 GetIOMold(); 



			virtual a_string GetSelfAddress(); 



			virtual U16 GetSelfPort(); 



			virtual a_string GetPeerAddress(); 



			virtual U16 GetPeerPort(); 



	};  //end class CTcpConnectorController



} //end namespace atom



#endif

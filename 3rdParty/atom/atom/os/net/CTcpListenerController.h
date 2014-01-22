#ifndef CTCPLISTENERCONTROLLER_H
#define CTCPLISTENERCONTROLLER_H
#include "../../interface/ITcpListenerController.h"
#include "../../interface/IInterface.h"
#include "tagDomain.h"
#include "../thread/CCriticalSection.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



	class CTcpListenerController : public ITcpListenerController
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



			CCriticalSection region;



			void Update(); 




		public:

			CTcpListenerController(); 



			virtual ~CTcpListenerController(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Open(const char * address, U16 port, U32 io_model); 



			virtual void Shut(); 



			//<p>Is connection active ?</p>
			virtual bool GetActive(); 



			//<p>Get connection's socket</p>
			virtual SOCKET GetSocket(); 



			//<p>Get connection's IO model's name</p>
			virtual U32 GetIOMold(); 



			virtual a_string GetSelfAddress(); 



			virtual U16 GetSelfPort(); 



			virtual U64 Accept(SOCKET socket); 



	};  //end class CTcpListenerController



} //end namespace atom



#endif

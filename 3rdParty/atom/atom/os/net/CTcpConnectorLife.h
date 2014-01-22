#ifndef CTCPCONNECTORLIFE_H
#define CTCPCONNECTORLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpConnectorLife : public IInstanceLife
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




		public:

			CTcpConnectorLife(); 



			virtual ~CTcpConnectorLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpConnectorLife



} //end namespace atom



#endif

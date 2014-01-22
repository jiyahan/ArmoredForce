#ifndef CTCPNETWORKSERVICELIFE_H
#define CTCPNETWORKSERVICELIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpNetworkServiceLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CTcpNetworkServiceLife(); 



			virtual ~CTcpNetworkServiceLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpNetworkServiceLife



} //end namespace atom



#endif

#ifndef CTCPEPOLLMODELLIFE_H
#define CTCPEPOLLMODELLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpEpollModelLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CTcpEpollModelLife(); 



			virtual ~CTcpEpollModelLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpEpollModelLife



} //end namespace atom



#endif

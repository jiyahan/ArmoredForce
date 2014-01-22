#ifndef CTCPKQUEUEMODELLIFE_H
#define CTCPKQUEUEMODELLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpKQueueModelLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CTcpKQueueModelLife(); 



			virtual ~CTcpKQueueModelLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpKQueueModelLife



} //end namespace atom



#endif

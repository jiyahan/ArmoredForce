#ifndef CINSTANCELIFECONTROLLER_H
#define CINSTANCELIFECONTROLLER_H
#include "../../interface/IInstanceLifeController.h"
#include "../../interface/IInterface.h"
#include "CInstanceLifeRemoveQueue.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



	class CInstanceLifeController : public IInstanceLifeController
	{


		private:


			IInterface * nest;



			CInstanceLifeRemoveQueue remove;




		public:

			CInstanceLifeController(); 



			virtual ~CInstanceLifeController(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual U64 Create(U32 type); 



			virtual bool Remove(U64 instance, U64 time = 10000); 



			virtual bool Remove(CU64Array & instances, U64 time = 10000); 



			virtual void Delete(U64 instance); 



			virtual void Delete(CU64Array & instances); 



			virtual void OnProcess(U64 time); 



			virtual bool Initiate();



			virtual bool Shutdown();



	};  //end class CInstanceLifeController



} //end namespace atom



#endif

#ifndef CINSTANCELIFEMAINTAINER_H
#define CINSTANCELIFEMAINTAINER_H
#include "../../interface/IMaintainable.h"
#include "../../interface/IInterface.h"



namespace atom
{
	


	class CInstanceLifeMaintainer : public IMaintainable
	{


		private:


			IInterface * nest;




		public:

			CInstanceLifeMaintainer(); 



			virtual ~CInstanceLifeMaintainer(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual U64 OnMaintenance(U64 now); 



	};  //end class CInstanceLifeMaintainer



} //end namespace atom



#endif

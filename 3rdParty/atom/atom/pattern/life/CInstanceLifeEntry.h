#ifndef CINSTANCELIFEENTRY_H
#define CINSTANCELIFEENTRY_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CInstanceLifeEntry : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CInstanceLifeEntry(); 



			virtual ~CInstanceLifeEntry(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CInstanceLifeEntry



} //end namespace atom



#endif

#ifndef CINSTANCEFACTORYLIFE_H
#define CINSTANCEFACTORYLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CInstanceFactoryLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CInstanceFactoryLife(); 



			virtual ~CInstanceFactoryLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CInstanceFactoryLife



} //end namespace atom



#endif

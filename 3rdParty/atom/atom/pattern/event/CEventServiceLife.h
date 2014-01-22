#ifndef CEVENTSERVICELIFE_H
#define CEVENTSERVICELIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CEventServiceLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CEventServiceLife(); 



			virtual ~CEventServiceLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CEventServiceLife



} //end namespace atom



#endif

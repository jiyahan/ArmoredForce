#ifndef CEVENTSPACELIFE_H
#define CEVENTSPACELIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{
	


	class CEventSpaceLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CEventSpaceLife(); 



			virtual ~CEventSpaceLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CEventSpaceLife



} //end namespace atom



#endif

#ifndef CEVENTSERVICEENTRY_H
#define CEVENTSERVICEENTRY_H
#include "../../interface/IEventServiceEntry.h"
#include "../../interface/IInterface.h"



namespace atom
{
	


	class CEventServiceEntry : public IEventServiceEntry
	{


		private:


			IInterface * nest;




		public:

			CEventServiceEntry(); 



			virtual ~CEventServiceEntry(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual U64 Create(); 



			virtual void Remove(U64 space); 



	};  //end class CEventServiceEntry



} //end namespace atom



#endif

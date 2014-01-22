#ifndef CEVENTEMITTER_H
#define CEVENTEMITTER_H
#include "../../interface/IEventEmitter.h"
#include "../../interface/IInterface.h"
#include "tagEvent.h"



namespace atom
{



	class CEventEmitter : public IEventEmitter
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			U64 node;




		public:

			CEventEmitter(); 



			virtual ~CEventEmitter(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Attach(U64 space); 



			virtual bool Attach(CObjectPtr & space); 



			virtual void Detach(); 



			virtual bool Report(const tagEvent & event); 



			virtual bool Report(const char * target, const tagEvent & event); 



	};  //end class CEventEmitter



} //end namespace atom



#endif

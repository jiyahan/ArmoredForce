#ifndef CINSTANCECONTAINERLISTENER_H
#define CINSTANCECONTAINERLISTENER_H
#include "../../interface/IInstanceContainerListener.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CInstanceContainerListener : public IInstanceContainerListener
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




		public:

			CInstanceContainerListener(); 



			virtual ~CInstanceContainerListener(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual void OnInsertInstance(CObjectPtr & instance); 



			virtual void OnRemoveInstance(CObjectPtr & instance); 



	};  //end class CInstanceContainerListener



} //end namespace atom



#endif

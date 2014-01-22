#ifndef CEVENTSERVICE_H
#define CEVENTSERVICE_H
#include "CEventServiceSingletonBind.h"
#include "CEventServiceThread.h"
#include "CEventServiceTimeline.h"
#include "CEventServiceEntry.h"
#include "CEventServiceLife.h"
#include "../container/CInstanceContainer.h"
#include "../container/CInstanceContainerListener.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"
#include "../../interface/IReferencedObject.h"



namespace atom
{



	class CEventService : public IReferencedObject, public CEventServiceSingletonBind
	{


		private:


			CReference counter;



			CEventServiceThread thread;



			CInstanceContainer container;



			CEventServiceTimeline timeline;



			CEventServiceEntry entry;



			CEventServiceLife life;



			CInstanceContainerListener listener;




		public:

			CEventService(); 



			virtual ~CEventService(); 



			virtual void SetName(U64 name); 



			virtual U64 GetName(); 



			virtual void SetType(U32 type); 



			virtual U32 GetType(); 



			virtual const char * ToString(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			U64 Create(); 



			void Remove(U64 name); 



			void Notify(U64 name); 



            bool Initiate(); 



            bool Shutdown(); 



	};  //end class CEventService



} //end namespace atom



#endif

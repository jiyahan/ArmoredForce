#ifndef CEVENTSPACECONTROLLER_H
#define CEVENTSPACECONTROLLER_H
#include "../../interface/IEventSpaceController.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "CEventSpaceControllerQueueBind.h"
#include "CEventSpaceControllerAliasBind.h"
#include "tagEvent.h"



namespace atom
{



	class CEventSpaceController : public IEventSpaceController
	{


		private:


			IInterface * nest;



			CEventSpaceControllerQueueBind queue;



			CCriticalSection queue_entry;



			CEventSpaceControllerAliasBind alias;



			CCriticalSection alias_entry;

			

		public:

			CEventSpaceController(); 



			virtual ~CEventSpaceController(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



			virtual bool Attach(CObjectPtr & receiver, const char * name = NULL); 



			virtual void Detach(U64 receiver); 



			virtual bool OnEvent(const tagEvent & event); 



			virtual void OnProcess(); 



			U64 GetTarget(a_string & name);



			void SendEvent(CObjectPtr & instance, tagEvent & value );



	};  //end class CEventSpaceController



} //end namespace atom



#endif

#ifndef CEVENTSERVICETHREAD_H
#define CEVENTSERVICETHREAD_H
#include "../../interface/IThreadControl.h"
#include "../../os/thread/CThread.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CSignal.h"



namespace atom
{
	


	class CEventServiceThread : public IThreadControl, public CThread
	{


		private:


			IInterface * nest;



			bool active;



			CSignal signal;




		public:

			CEventServiceThread(); 



			~CEventServiceThread(); 



			void SetActive(bool active); 



			bool GetActive(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			virtual U32 Run(); 



			virtual bool OnBegin(); 



			virtual bool OnClose(); 



			virtual void OnAwake(); 



	};  //end class CEventServiceThread



} //end namespace atom



#endif

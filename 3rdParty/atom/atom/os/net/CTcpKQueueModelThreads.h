#ifndef CTCPKQUEUEMODELTHREADS_H
#define CTCPKQUEUEMODELTHREADS_H
#include "../../interface/IMultiThreadControl.h"
#include "../../interface/IInterface.h"
#include "CTcpKQueueModelThreadWorker.h"



namespace atom
{



	class CTcpKQueueModelThreads : public IMultiThreadControl
	{


		private:


			IInterface * nest;



			U32 amount;



			#ifdef __APPLE__
			CTcpKQueueModelThreadWorker worker[MAX_KQUEUE_THREAD];
			#endif




		public:

			CTcpKQueueModelThreads(); 



			virtual ~CTcpKQueueModelThreads(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool OnBegin(); 



			virtual bool OnClose(); 



			virtual void OnAwake(); 



			virtual bool OnBegin(U32 index); 



			virtual bool OnClose(U32 index); 



			virtual void OnAwake(U32 index); 



			virtual void SetThreadAmount(U32 value); 



			virtual U32 GetThreadAmount(); 



	};  //end class CTcpKQueueModelThreads



} //end namespace atom



#endif

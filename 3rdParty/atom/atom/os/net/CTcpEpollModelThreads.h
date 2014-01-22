#ifndef CTCPEPOLLMODELTHREADS_H
#define CTCPEPOLLMODELTHREADS_H
#include "../../interface/IMultiThreadControl.h"
#include "../../interface/IInterface.h"
#include "CTcpEpollModelThreadWorker.h"



namespace atom
{



	class CTcpEpollModelThreads : public IMultiThreadControl
	{


		private:


			IInterface * nest;



			U32 amount;



			#ifdef __linux
			CTcpEpollModelThreadWorker worker[MAX_EPOLL_THREAD];
			#endif




		public:

			CTcpEpollModelThreads(); 



			virtual ~CTcpEpollModelThreads(); 



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



	};  //end class CTcpEpollModelThreads



} //end namespace atom



#endif

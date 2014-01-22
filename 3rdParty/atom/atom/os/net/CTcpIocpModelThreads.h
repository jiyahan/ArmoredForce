#ifndef CTCPIOCPMODELTHREADS_H
#define CTCPIOCPMODELTHREADS_H
#include "../../interface/IMultiThreadControl.h"
#include "../../interface/IInterface.h"
#include "CTcpIocpModelThreadWorker.h"



namespace atom
{



	class CTcpIocpModelThreads : public IMultiThreadControl
	{


		private:


			IInterface * nest;



			#ifdef _WIN32
			U32 amount;



			CTcpIocpModelThreadWorker worker[MAX_IOCP_THREAD];
			#endif



		public:

			CTcpIocpModelThreads(); 



			virtual ~CTcpIocpModelThreads(); 



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



	};  //end class CTcpIocpModelThreads



} //end namespace atom



#endif

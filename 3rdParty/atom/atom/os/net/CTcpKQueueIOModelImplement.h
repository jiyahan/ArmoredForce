#ifndef CTCPKQUEUEIOMODELIMPLEMENT_H
#define CTCPKQUEUEIOMODELIMPLEMENT_H
#include "../../interface/ITcpKQueueIOModel.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../memory/CMemory.h"
#include "CTcpKQueueIOModelImplementBind.h"
#include "CKQueueEvent.h"
#include "tagDomain.h"



namespace atom
{



	class CTcpKQueueIOModelImplement : public ITcpKQueueIOModel
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			#ifdef __APPLE__
			int port[MAX_KQUEUE_THREAD];



			U32 size;



			bool active;



			CTcpKQueueIOModelImplementBind allocator;



			CObjectPtr ObtainBySocket(SOCKET socket); 



			bool Report(CObjectPtr & connector, U32 eid); 



			bool Change(int hs, int filter, int flag, void * data); 



			bool OnAccept(CKQueueEvent * op); 



			bool OnSend(CKQueueEvent * op); 



			bool OnReceive(CKQueueEvent * op); 
			#endif




		public:

			CTcpKQueueIOModelImplement(); 



			virtual ~CTcpKQueueIOModelImplement(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual SOCKET Create(); 



			virtual void Remove(SOCKET socket); 



			virtual bool Attach(U64 name); 



			virtual bool Detach(U64 name); 



			virtual CObjectPtr Obtain(U64 name); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



			virtual bool Listen(U64 listener, const tagDomain & domain); 



			virtual bool Connect(U64 connector, const tagDomain & domain); 



			virtual bool Send(U64 connector, CMemory & data, size_t offset, size_t length); 



			virtual bool Receive(U64 connector); 



			virtual bool Accept(U64 listener); 



			virtual I32 OnProcess(U32 id); 



			virtual U32 GetAmount(); 



			virtual void PreShutdown(); 



	};  //end class CTcpKQueueIOModelImplement



} //end namespace atom



#endif

#ifndef CTCPIOCPIOMODELIMPLEMENT_H
#define CTCPIOCPIOMODELIMPLEMENT_H
#include "../../interface/ITcpIocpIOModel.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"
#include "CTcpIocpIOModelImplementBind.h"
#include "tagDomain.h"
#include "../memory/CMemory.h"
#include "tagIocpOperation.h"
#include "CIocpBuffer.h"
#include "CIocpOverlap.h"
#include "tagIocpEvent.h"



namespace atom
{



	class CTcpIocpIOModelImplement : public ITcpIocpIOModel
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			#ifdef _WIN32
			HANDLE port[MAX_IOCP_HANDLE];



			U32 size;



			CTcpIocpIOModelImplementBind allocator;



			bool OnAccept(tagIocpOperation * packet); 



			bool OnAccept(SOCKET listener, SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol); 



			bool OnSend(size_t bytes, tagIocpOperation * packet); 



			bool OnSend(SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol); 



			bool OnReceive(size_t bytes, tagIocpOperation * packet); 



			bool OnReceive(SOCKET hs, CIocpBuffer * wb, CIocpOverlap * ol); 



			bool GetCompletionEvent(U32 index, tagIocpEvent * ioe, U64 timeout); 



			bool Report(CObjectPtr & connector, U32 event); 
			#endif




		public:

			CTcpIocpIOModelImplement(); 



			virtual ~CTcpIocpIOModelImplement(); 



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



	};  //end class CTcpIocpIOModelImplement



} //end namespace atom



#endif

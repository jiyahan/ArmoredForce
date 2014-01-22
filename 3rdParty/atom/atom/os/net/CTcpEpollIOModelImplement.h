#ifndef CTCPEPOLLIOMODELIMPLEMENT_H
#define CTCPEPOLLIOMODELIMPLEMENT_H
#include "../../interface/ITcpEpollIOModel.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"
#include "tagDomain.h"
#include "../memory/CMemory.h"



namespace atom
{



	class CTcpEpollIOModelImplement : public ITcpEpollIOModel
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			#ifdef __linux
			int epolls[32];



			U32 amount;



			bool active;



			bool OnAccept(CObjectPtr & object); 



			bool OnReceive(CObjectPtr & object); 



			bool OnSend(CObjectPtr & object); 



			bool Report(CObjectPtr & connector, U32 eid);
			#endif




		public:

			CTcpEpollIOModelImplement(); 



			virtual ~CTcpEpollIOModelImplement(); 



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



	};  //end class CTcpEpollIOModelImplement



} //end namespace atom



#endif

#ifndef CTCPSELECTMODELIMPLEMENT_H
#define CTCPSELECTMODELIMPLEMENT_H
#include "../../interface/ITcpSelectIOModel.h"
#include "../../interface/IInterface.h"
#include "tagTcpSelectOperation.h"
#include "../thread/CCriticalSection.h"
#include "../thread/CReference.h"
#include "../../utility/tool/CObjectPtr.h"
#include "tagDomain.h"
#include "../memory/CMemory.h"



namespace atom
{



	class CTcpSelectModelImplement : public ITcpSelectIOModel
	{


		public:


			typedef std::map<SOCKET, U64, less<SOCKET>, atom_allocator<pair<SOCKET, U64> > >  CTcpSelectModelSocketBind ;

		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			bool active;



			tagTcpSelectOperation::CTcpSelectOperationBind sended;



			CTcpSelectModelSocketBind client;



			CTcpSelectModelSocketBind server;



			bool client_update;



			bool server_update;



			CCriticalSection region;



			CReference serial;



			CObjectPtr ObtainBySocket(SOCKET name); 



			bool OnAccept(SOCKET socket); 



			bool OnSend(const tagTcpSelectOperation & value); 



			bool OnReceive(SOCKET socket); 



			bool Report(CObjectPtr & connector, U32 msg); 




		public:

			CTcpSelectModelImplement(); 



			virtual ~CTcpSelectModelImplement(); 



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



			virtual void SetActive(bool value); 



			virtual I32 OnProcess(); 



	};  //end class CTcpSelectModelImplement



} //end namespace atom



#endif

#ifndef ITCPIOMODEL_H
#define ITCPIOMODEL_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../os/net/tagDomain.h"
#include "../os/memory/CMemory.h"



namespace atom
{
	


	class ITcpIOModel : public IEmbedInterface
	{




		public:

			virtual SOCKET Create() = 0; 



			virtual void Remove(SOCKET socket) = 0; 



			virtual bool Attach(U64 name) = 0; 



			virtual bool Detach(U64 name) = 0; 



			virtual CObjectPtr Obtain(U64 name) = 0; 



			virtual bool Initiate() = 0; 



			virtual bool Shutdown() = 0; 



			virtual bool Listen(U64 listener, const tagDomain & domain) = 0; 



			virtual bool Connect(U64 connector, const tagDomain & domain) = 0; 



			virtual bool Send(U64 connector, CMemory & data, size_t offset, size_t length) = 0; 



			virtual bool Receive(U64 connector) = 0; 



			virtual bool Accept(U64 listener) = 0; 



	};  //end class ITcpIOModel



} //end namespace atom



#endif

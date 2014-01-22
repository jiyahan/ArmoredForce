#ifndef ITCPCONNECTIONCONTROLLER_H
#define ITCPCONNECTIONCONTROLLER_H
#include "IEmbedInterface.h"
#include "../utility/stl/a_string.h"



namespace atom
{



	class ITcpConnectionController : public IEmbedInterface
	{




		public:

			virtual bool Open(const char * address, U16 port, U32 io_model) = 0; 



			virtual void Shut() = 0; 



			//<p>Is connection active ?</p>
			virtual bool GetActive() = 0; 



			//<p>Get connection's socket</p>
			virtual SOCKET GetSocket() = 0; 



			//<p>Get connection's IO model's name</p>
			virtual U32 GetIOMold() = 0; 



			virtual a_string GetSelfAddress() = 0; 



			virtual U16 GetSelfPort() = 0; 



	};  //end class ITcpConnectionController



} //end namespace atom



#endif

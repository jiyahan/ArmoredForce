#ifndef ITCPCONNECTORCONTROLLER_H
#define ITCPCONNECTORCONTROLLER_H
#include "ITcpConnectionController.h"
#include "../utility/stl/a_string.h"



namespace atom
{



	class ITcpConnectorController : public ITcpConnectionController
	{




		public:

			virtual bool Open(SOCKET socket, U32 io_model) = 0; 



			virtual a_string GetPeerAddress() = 0; 



			virtual U16 GetPeerPort() = 0; 



	};  //end class ITcpConnectorController



} //end namespace atom



#endif

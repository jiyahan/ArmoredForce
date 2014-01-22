#ifndef ITCPLISTENERCONTROLLER_H
#define ITCPLISTENERCONTROLLER_H
#include "ITcpConnectionController.h"



namespace atom
{



	class ITcpListenerController : public ITcpConnectionController
	{




		public:

			virtual U64 Accept(SOCKET socket) = 0; 



	};  //end class ITcpListenerController



} //end namespace atom



#endif

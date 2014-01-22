#ifndef ITCPEPOLLIOMODEL_H
#define ITCPEPOLLIOMODEL_H
#include "ITcpIOModel.h"



namespace atom
{



	class ITcpEpollIOModel : public ITcpIOModel
	{




		public:

			virtual I32 OnProcess(U32 id) = 0; 



			virtual U32 GetAmount() = 0; 



			virtual void PreShutdown() = 0; 



	};  //end class ITcpEpollIOModel



} //end namespace atom



#endif

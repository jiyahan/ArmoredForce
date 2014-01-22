#ifndef ITCPKQUEUEIOMODEL_H
#define ITCPKQUEUEIOMODEL_H
#include "ITcpIOModel.h"



namespace atom
{



	class ITcpKQueueIOModel : public ITcpIOModel
	{




		public:

			virtual I32 OnProcess(U32 id) = 0; 



			virtual U32 GetAmount() = 0; 



			virtual void PreShutdown() = 0; 



	};  //end class ITcpKQueueIOModel



} //end namespace atom



#endif

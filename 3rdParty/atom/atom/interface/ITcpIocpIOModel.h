#ifndef ITCPIOCPIOMODEL_H
#define ITCPIOCPIOMODEL_H
#include "ITcpIOModel.h"



namespace atom
{



	class ITcpIocpIOModel : public ITcpIOModel
	{




		public:

			virtual I32 OnProcess(U32 index) = 0; 



			virtual U32 GetAmount() = 0; 



			virtual void PreShutdown() = 0; 



	};  //end class ITcpIocpIOModel



} //end namespace atom



#endif

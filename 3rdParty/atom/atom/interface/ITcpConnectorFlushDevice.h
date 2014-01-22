#ifndef ITCPCONNECTORFLUSHDEVICE_H
#define ITCPCONNECTORFLUSHDEVICE_H
#include "IFlushDevice.h"



namespace atom
{



	class ITcpConnectorFlushDevice : public IFlushDevice
	{




		public:

			virtual bool Bind(U32 iomodel) = 0; 



			virtual bool OnDataSent(size_t bytes) = 0; 



			virtual void Reset() = 0; 



	};  //end class ITcpConnectorFlushDevice



} //end namespace atom



#endif

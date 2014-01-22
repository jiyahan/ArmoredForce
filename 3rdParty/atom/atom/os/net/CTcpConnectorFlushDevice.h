#ifndef CTCPCONNECTORFLUSHDEVICE_H
#define CTCPCONNECTORFLUSHDEVICE_H
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IInterface.h"
#include "../thread/CReference.h"
#include "CTcpConnectorFlushQueue.h"
#include "../thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../memory/CMemory.h"



namespace atom
{



	class CTcpConnectorFlushDevice : public ITcpConnectorFlushDevice
	{


		private:


			IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif



			CReference counter;



			CTcpConnectorFlushQueue prepare;



			CTcpConnectorFlushQueue::CTcpConnectorFlushQueueBind waiting;



			CCriticalSection protect;



			U64 connect;



			CObjectPtr iomodel;



			CCriticalSection section;



			size_t Send(); 




		public:

			CTcpConnectorFlushDevice(); 



			virtual ~CTcpConnectorFlushDevice(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool OnFlush(CMemory & value); 



			virtual bool Bind(U32 iomodel); 



			virtual bool OnDataSent(size_t bytes); 



			virtual void Reset(); 



	};  //end class CTcpConnectorFlushDevice



} //end namespace atom



#endif

#ifndef CTCPKQUEUEMODELTHREADWORKER_H
#define CTCPKQUEUEMODELTHREADWORKER_H
#include "../thread/CThread.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CTcpKQueueModelThreadWorker : public CThread
	{


		private:


			CObjectPtr object;



			U32 serial;




		public:

			CTcpKQueueModelThreadWorker(); 



			virtual ~CTcpKQueueModelThreadWorker(); 



			virtual U32 Run(); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			void SetObject(CObjectPtr & value); 



			void SetSerial(U32 value); 



	};  //end class CTcpKQueueModelThreadWorker



} //end namespace atom



#endif

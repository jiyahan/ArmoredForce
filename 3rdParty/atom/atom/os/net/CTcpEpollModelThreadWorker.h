#ifndef CTCPEPOLLMODELTHREADWORKER_H
#define CTCPEPOLLMODELTHREADWORKER_H
#include "../thread/CThread.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CTcpEpollModelThreadWorker : public CThread
	{


		private:


			CObjectPtr object;



			U32 serial;




		public:

			CTcpEpollModelThreadWorker(); 



			virtual ~CTcpEpollModelThreadWorker(); 



			virtual U32 Run(); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			void SetObject(CObjectPtr & value); 



			void SetSerial(U32 value); 



	};  //end class CTcpEpollModelThreadWorker



} //end namespace atom



#endif

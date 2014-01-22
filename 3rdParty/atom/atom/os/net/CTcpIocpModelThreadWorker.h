#ifndef CTCPIOCPMODELTHREADWORKER_H
#define CTCPIOCPMODELTHREADWORKER_H
#include "../thread/CThread.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CTcpIocpModelThreadWorker : public CThread
	{


		private:


			CObjectPtr object;



			U32 serial;




		public:

			CTcpIocpModelThreadWorker(); 



			virtual ~CTcpIocpModelThreadWorker(); 



			virtual U32 Run(); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			void SetObject(CObjectPtr & value); 



			void SetSerial(U32 value);



	};  //end class CTcpIocpModelThreadWorker



} //end namespace atom



#endif

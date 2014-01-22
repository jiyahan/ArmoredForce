#ifndef TAGTCPKQUEUEOPERATION_H
#define TAGTCPKQUEUEOPERATION_H
#include "../../utility/tool/CObjectPtr.h"
#include "../memory/CMemory.h"



namespace atom
{



	struct tagTcpKQueueOperation
	{


		private:


			CObjectPtr object;




		public:


			CMemory memory;



			size_t offset;



			size_t length;



			tagTcpKQueueOperation(); 



			virtual ~tagTcpKQueueOperation(); 



			void Reset(); 



			void Attach(CObjectPtr & value); 



			void Detach(); 



			CObjectPtr Object(); 



	};  //end struct tagTcpKQueueOperation



} //end namespace atom



#endif

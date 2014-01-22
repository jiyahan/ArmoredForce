#ifndef CINSTANCELIFEREMOVEQUEUE_H
#define CINSTANCELIFEREMOVEQUEUE_H
#include "CInstanceLifeRemoveQueueBind.h"
#include "../../utility/stl/CU64Array.h"


namespace atom
{



	class CInstanceLifeRemoveQueue
	{


		private:


			CInstanceLifeRemoveQueueBind queues[LIFE_REMOVE_QUEUE];




		public:

			CInstanceLifeRemoveQueue(); 



			virtual ~CInstanceLifeRemoveQueue(); 



			void Clear(); 



			void Insert(U64 time, U64 instance); 



			void Obtain(U64 time, CU64Array & instances); 



	};  //end class CInstanceLifeRemoveQueue



} //end namespace atom



#endif

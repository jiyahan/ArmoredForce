#ifndef IINSTANCELIFECONTROLLER_H
#define IINSTANCELIFECONTROLLER_H
#include "IEmbedInterface.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{



	class IInstanceLifeController : public IEmbedInterface
	{




		public:

			virtual U64 Create(U32 type) = 0; 



			virtual bool Remove(U64 instance, U64 time=10000) = 0; 



			virtual bool Remove(CU64Array & instances, U64 time=10000) = 0; 



			virtual void Delete(U64 instance) = 0; 



			virtual void Delete(CU64Array & instances) = 0; 



			virtual void OnProcess(U64 time) = 0; 



			virtual bool Initiate() = 0;



			virtual bool Shutdown() = 0;



	};  //end class IInstanceLifeController



} //end namespace atom



#endif

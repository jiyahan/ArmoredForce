#ifndef IEVENTSERVICEENTRY_H
#define IEVENTSERVICEENTRY_H
#include "IEmbedInterface.h"



namespace atom
{



	class IEventServiceEntry : public IEmbedInterface
	{




		public:

			virtual U64 Create() = 0; 



			virtual void Remove(U64 space) = 0; 



	};  //end class IEventServiceEntry



} //end namespace atom



#endif

#ifndef IEVENTSERVICETIMELINE_H
#define IEVENTSERVICETIMELINE_H
#include "IEmbedInterface.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{
	


	class IEventServiceTimeline : public IEmbedInterface
	{




		public:

			virtual void Mark(U64 time, U64 instance) = 0; 



			virtual void Forward(U64 time, CU64Array & instances) = 0; 



	};  //end class IEventServiceTimeline



} //end namespace atom



#endif

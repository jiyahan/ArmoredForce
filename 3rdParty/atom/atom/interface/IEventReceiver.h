#ifndef IEVENTRECEIVER_H
#define IEVENTRECEIVER_H
#include "IEmbedInterface.h"
#include "../pattern/event/tagEvent.h"



namespace atom
{



	class IEventReceiver : public IEmbedInterface
	{




		public:

			virtual bool OnEvent(const tagEvent & event) = 0; 



	};  //end class IEventReceiver


} //end namespace atom



#endif

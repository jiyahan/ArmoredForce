#ifndef IINSTANCELIFENOTIFYRECEIVER_H
#define IINSTANCELIFENOTIFYRECEIVER_H
#include "IEmbedInterface.h"



namespace atom
{



	class IInstanceLifeNotifyReceiver : public IEmbedInterface
	{




		public:

			virtual bool OnCreateInstance(U64 name) = 0; 



			virtual bool OnRemoveInstance(U64 name) = 0; 



	};  //end class IInstanceLifeNotifyReceiver



} //end namespace atom



#endif

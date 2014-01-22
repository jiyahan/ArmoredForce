#ifndef IEVENTSPACECONTROLLER_H
#define IEVENTSPACECONTROLLER_H
#include "IEventReceiver.h"
#include "../utility/tool/CObjectPtr.h"
#include "../pattern/event/tagEvent.h"



namespace atom
{
	


	class IEventSpaceController : public IEventReceiver
	{




		public:

			virtual bool Initiate() = 0; 



			virtual bool Shutdown() = 0; 



			virtual bool Attach(CObjectPtr & receiver, const char * name = NULL) = 0; 



			virtual void Detach(U64 receiver) = 0; 



			virtual void OnProcess() = 0; 



	};  //end class IEventSpaceController



} //end namespace atom



#endif

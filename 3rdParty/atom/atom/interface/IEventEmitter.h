#ifndef IEVENTEMITTER_H
#define IEVENTEMITTER_H
#include "IEmbedInterface.h"
#include "../pattern/event/tagEvent.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



	class IEventEmitter : public IEmbedInterface
	{




		public:

			virtual bool Attach(U64 space) = 0; 



			virtual bool Attach(CObjectPtr & space) = 0; 



			virtual void Detach() = 0; 



			virtual bool Report(const tagEvent & event) = 0; 



			virtual bool Report(const char * target, const tagEvent & event) = 0; 



	};  //end class IEventEmitter



} //end namespace atom



#endif

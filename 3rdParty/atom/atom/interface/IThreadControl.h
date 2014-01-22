#ifndef ITHREADCONTROL_H
#define ITHREADCONTROL_H
#include "IEmbedInterface.h"



namespace atom
{



	class IThreadControl : public IEmbedInterface
	{




		public:

			virtual bool OnBegin() = 0; 



			virtual bool OnClose() = 0; 



			virtual void OnAwake() = 0; 



	};  //end class IThreadControl



} //end namespace atom



#endif

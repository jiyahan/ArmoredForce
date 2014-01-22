#ifndef IINSTANCELIFE_H
#define IINSTANCELIFE_H
#include "IEmbedInterface.h"



namespace atom
{



	class IInstanceLife : public IEmbedInterface
	{




		public:

			virtual bool Initiate() = 0; 



			virtual bool Shutdown() = 0; 



	};  //end class IInstanceLife



} //end namespace atom



#endif

#ifndef IINSTANCELIFENOTIFY_H
#define IINSTANCELIFENOTIFY_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	class IInstanceLifeNotify : public IEmbedInterface
	{




		public:

			virtual void SetReceiver(CObjectPtr & value) = 0; 



			virtual CObjectPtr GetReceiver() = 0; 



	};  //end class IInstanceLifeNotify



} //end namespace atom



#endif

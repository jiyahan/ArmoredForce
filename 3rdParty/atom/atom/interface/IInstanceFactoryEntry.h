#ifndef IINSTANCEFACTORYENTRY_H
#define IINSTANCEFACTORYENTRY_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	class IInstanceFactoryEntry : public IEmbedInterface
	{




		public:

			virtual U64 Product(U32 type) = 0; 



			virtual CObjectPtr Inquire(U64 instance) = 0; 



			virtual bool Destroy(U64 instance) = 0; 



			virtual void Recycle() = 0; 



			virtual bool Initiate() = 0; 



			virtual bool Shutdown() = 0; 



	};  //end class IInstanceFactoryEntry



} //end namespace atom



#endif

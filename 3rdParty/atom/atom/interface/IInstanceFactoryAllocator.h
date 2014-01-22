#ifndef IINSTANCEFACTORYALLOCATOR_H
#define IINSTANCEFACTORYALLOCATOR_H
#include "IEmbedInterface.h"
#include "../pattern/object/CReferencedObject.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{
	


	class IInstanceFactoryAllocator : public IEmbedInterface
	{




		public:

			virtual bool Attach(CObjectPtr & allocator) = 0; 



			virtual bool Detach(CObjectPtr & allocator) = 0; 



			virtual CReferencedObject * Product(U32 type) = 0; 



			virtual void Destroy(CReferencedObject * value) = 0; 



	};  //end class IInstanceFactoryAllocator



} //end namespace atom



#endif

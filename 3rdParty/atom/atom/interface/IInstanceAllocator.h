#ifndef IINSTANCEALLOCATOR_H
#define IINSTANCEALLOCATOR_H
#include "IEmbedInterface.h"
#include "../pattern/object/CReferencedObject.h"



namespace atom
{



	class IInstanceAllocator : public IEmbedInterface
	{




		public:

			virtual CReferencedObject * Product(U32 type) = 0; 



			virtual void Destroy(CReferencedObject * value) = 0; 



			virtual void Confine(U32 & lower, U32 & upper) = 0; 



	};  //end class IInstanceAllocator



} //end namespace atom



#endif

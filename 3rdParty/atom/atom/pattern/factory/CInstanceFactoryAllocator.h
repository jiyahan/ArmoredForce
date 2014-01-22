#ifndef CINSTANCEFACTORYALLOCATOR_H
#define CINSTANCEFACTORYALLOCATOR_H
#include "../../interface/IInstanceFactoryAllocator.h"
#include "../../interface/IInterface.h"
#include "tagAllocator.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../interface/IReferencedObject.h"



namespace atom
{



	class CInstanceFactoryAllocator : public IInstanceFactoryAllocator
	{


		private:


			IInterface * nest;



			tagAllocator list[ALLOCATOR_TOTAL];



		public:

			CInstanceFactoryAllocator(); 



			virtual ~CInstanceFactoryAllocator(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Attach(CObjectPtr & allocator); 



			virtual bool Detach(CObjectPtr & allocator); 



			virtual CReferencedObject * Product(U32 type); 



			virtual void Destroy(CReferencedObject * value); 



	};  //end class CInstanceFactoryAllocator



} //end namespace atom



#endif

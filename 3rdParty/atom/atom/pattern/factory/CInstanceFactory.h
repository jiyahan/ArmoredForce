#ifndef CINSTANCEFACTORY_H
#define CINSTANCEFACTORY_H
#include "../../interface/IReferencedObject.h"
#include "CInstanceFactorySingletonBind.h"
#include "CInstanceFactoryMaintainer.h"
#include "CInstanceFactoryEntry.h"
#include "CInstanceFactoryLife.h"
#include "CInstanceFactoryAllocator.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	class CInstanceFactory : public IReferencedObject, public CInstanceFactorySingletonBind
	{


		private:


			CInstanceFactoryMaintainer maintainer;



			CInstanceFactoryEntry entry;



			CInstanceFactoryAllocator allocator;



			CReference counter;



			CInstanceFactoryLife life;



		public:

			CInstanceFactory(); 



			virtual ~CInstanceFactory(); 



			bool Initiate(); 



			bool Shutdown(); 



			virtual void SetName(U64 name); 



			virtual U64 GetName(); 



			virtual void SetType(U32 type); 



			virtual U32 GetType(); 



			virtual const char * ToString(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			bool Attach(CObjectPtr & allocator); 



			bool Detach(CObjectPtr & allocator); 



			U64 Product(U32 type); 



			bool Destroy(U64 instance); 



			CObjectPtr Inquire(U64 instance); 



	};  //end class CInstanceFactory



} //end namespace atom



#endif

#ifndef CATOMALLOCATOR_H
#define CATOMALLOCATOR_H
#include "CAtomAllocatorSingletonBind.h"
#include "CAtomInstanceAllocator.h"
#include "../../interface/IReferencedObject.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CAtomAllocator : public IReferencedObject, public CAtomAllocatorSingletonBind
	{


		private:


			CAtomInstanceAllocator allocator;



			CReference counter;




		public:

			CAtomAllocator(); 



			virtual ~CAtomAllocator(); 



			virtual void SetName(U64 name); 



			virtual U64 GetName(); 



			virtual void SetType(U32 type); 



			virtual U32 GetType(); 



			virtual const char * ToString(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CAtomAllocator



} //end namespace atom



#endif

#ifndef CATOMINSTANCEALLOCATOR_H
#define CATOMINSTANCEALLOCATOR_H
#include "../../interface/IInstanceAllocator.h"
#include "../../interface/IInterface.h"
#include "../../interface/IReferencedObject.h"



namespace atom
{



	class CAtomInstanceAllocator : public IInstanceAllocator
	{


		private:


			IInterface * nest;




		public:

			CAtomInstanceAllocator(); 



			virtual ~CAtomInstanceAllocator(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual CReferencedObject * Product(U32 type); 



			virtual void Destroy(CReferencedObject * value); 



			virtual void Confine(U32 & lower, U32 & upper); 



	};  //end class CAtomInstanceAllocator



} //end namespace atom



#endif

#ifndef CINSTANCEFACTORYENTRY_H
#define CINSTANCEFACTORYENTRY_H
#include "../../interface/IInstanceFactoryEntry.h"
#include "../../interface/IInterface.h"
#include "CInstances.h"
#include "CInstanceFactoryRemoveBind.h"
#include "../../os/thread/CReference.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{
	


	class CInstanceFactoryEntry : public IInstanceFactoryEntry
	{


		private:


			IInterface * nest;



			CInstances instances;



			CInstanceFactoryRemoveBind remove;



			CReference name;



			bool active;


	
			CCriticalSection scopes;



		public:

			CInstanceFactoryEntry(); 



			virtual ~CInstanceFactoryEntry(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



			virtual U64 Product(U32 type); 



			virtual CObjectPtr Inquire(U64 instance); 



			virtual bool Destroy(U64 instance); 



			virtual void Recycle(); 



	};  //end class CInstanceFactoryEntry



} //end namespace atom



#endif

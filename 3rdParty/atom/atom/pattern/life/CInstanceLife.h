#ifndef CINSTANCELIFE_H
#define CINSTANCELIFE_H
#include "../../interface/IReferencedObject.h"
#include "CInstanceLifeSingletonBind.h"
#include "CInstanceLifeController.h"
#include "CInstanceLifeMaintainer.h"
#include "CInstanceLifeReference.h"
#include "CInstanceLifeEntry.h"
#include "../../os/thread/CThread.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CInstanceLife : public IReferencedObject, public CInstanceLifeSingletonBind
	{


		private:


			CInstanceLifeController controller;



			CInstanceLifeMaintainer maintainer;



			CInstanceLifeReference reference;



			CReference counter;



			CInstanceLifeEntry life;



		public:

			CInstanceLife(); 



			virtual ~CInstanceLife(); 



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



			U64 Create(U32 type); 



			int Increase(U64 instance); 



			int Decrease(U64 instance); 



			int GetReference(U64 instance); 



	};  //end class CInstanceLife



} //end namespace atom



#endif

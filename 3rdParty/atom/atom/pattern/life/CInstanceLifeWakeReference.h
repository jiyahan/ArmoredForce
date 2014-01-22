#ifndef CINSTANCELIFEWAKEREFERENCE_H
#define CINSTANCELIFEWAKEREFERENCE_H
#include "CInstanceLifeWakeReferenceBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



	class CInstanceLifeWakeReference
	{


		private:


			CInstanceLifeWakeReferenceBind instances;



			CCriticalSection section;




		public:

			CInstanceLifeWakeReference(); 



			virtual ~CInstanceLifeWakeReference(); 



			bool Insert(U64 instance, CObjectPtr & receiver); 



			bool Remove(U64 instance, CObjectPtr & receiver); 



			int Increase(U64 instance); 



			int Decrease(U64 instance); 



			void Clear(CObjectPtr & receiver); 



			int GetReference(U64 instance); 



			void GetInstances(CU64Array & instances); 



	};  //end class CInstanceLifeWakeReference



} //end namespace atom



#endif

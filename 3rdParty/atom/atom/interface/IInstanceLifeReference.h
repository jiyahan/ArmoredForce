#ifndef IINSTANCELIFEREFERENCE_H
#define IINSTANCELIFEREFERENCE_H
#include "IInstanceLifeNotify.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{
	


	class IInstanceLifeReference : public IInstanceLifeNotify
	{




		public:

			virtual bool Insert(U64 instance) = 0; 



			virtual bool Remove(U64 instance) = 0; 



			virtual int Increase(U64 instance) = 0; 



			virtual int Decrease(U64 instance) = 0; 



			virtual int GetReference(U64 instance) = 0; 



			virtual void GetInstances(CU64Array & instances) = 0; 



			virtual bool Initiate() = 0;



			virtual bool Shutdown() = 0;



	};  //end class IInstanceLifeReference



} //end namespace atom



#endif

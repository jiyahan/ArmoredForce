#ifndef CINSTANCELIFEREMOVEQUEUE_H
#define CINSTANCELIFEREMOVEQUEUE_H
//Begin section for file CInstanceLifeRemoveQueue.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeRemoveQueue.h
#include "CInstanceLifeRemoveQueueBind.h"
#include "../../utility/stl/CU64Array.h"


namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceLifeRemoveQueue
	{

		//Begin section for atom::CInstanceLifeRemoveQueue
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceLifeRemoveQueue

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeRemoveQueueBind queues[LIFE_REMOVE_QUEUE];




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeRemoveQueue(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceLifeRemoveQueue(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Clear(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Insert(U64 time, U64 instance); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Obtain(U64 time, CU64Array & instances); 



	};  //end class CInstanceLifeRemoveQueue



} //end namespace atom



#endif

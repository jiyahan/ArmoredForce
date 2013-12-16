#ifndef CINSTANCELIFEWAKEREFERENCE_H
#define CINSTANCELIFEWAKEREFERENCE_H
//Begin section for file CInstanceLifeWakeReference.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeWakeReference.h
#include "CInstanceLifeWakeReferenceBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceLifeWakeReference
	{

		//Begin section for atom::CInstanceLifeWakeReference
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceLifeWakeReference

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeWakeReferenceBind instances;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection section;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CInstanceLifeWakeReference(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CInstanceLifeWakeReference(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Insert(U64 instance, CObjectPtr & receiver); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Remove(U64 instance, CObjectPtr & receiver); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			int Increase(U64 instance); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			int Decrease(U64 instance); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Clear(CObjectPtr & receiver); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			int GetReference(U64 instance); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void GetInstances(CU64Array & instances); 



	};  //end class CInstanceLifeWakeReference



} //end namespace atom



#endif

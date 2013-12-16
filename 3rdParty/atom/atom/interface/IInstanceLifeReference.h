#ifndef IINSTANCELIFEREFERENCE_H
#define IINSTANCELIFEREFERENCE_H
//Begin section for file IInstanceLifeReference.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceLifeReference.h
#include "IInstanceLifeNotify.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceLifeReference : public IInstanceLifeNotify
	{

		//Begin section for atom::IInstanceLifeReference
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceLifeReference



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Insert(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Remove(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int Increase(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int Decrease(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int GetReference(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void GetInstances(CU64Array & instances) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0;



	};  //end class IInstanceLifeReference



} //end namespace atom



#endif

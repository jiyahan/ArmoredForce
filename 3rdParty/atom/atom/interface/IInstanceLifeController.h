#ifndef IINSTANCELIFECONTROLLER_H
#define IINSTANCELIFECONTROLLER_H
//Begin section for file IInstanceLifeController.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceLifeController.h
#include "IEmbedInterface.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class IInstanceLifeController : public IEmbedInterface
	{

		//Begin section for atom::IInstanceLifeController
		//TODO: Add attributes that you want preserved
		//End section for atom::IInstanceLifeController



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual U64 Create(U32 type) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Remove(U64 instance, U64 time=10000) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Remove(CU64Array & instances, U64 time=10000) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Delete(U64 instance) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Delete(CU64Array & instances) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void OnProcess(U64 time) = 0; 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Initiate() = 0;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown() = 0;



	};  //end class IInstanceLifeController



} //end namespace atom



#endif

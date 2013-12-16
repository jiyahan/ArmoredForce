#ifndef CINSTANCEUTILITY_H
#define CINSTANCEUTILITY_H
//Begin section for file CInstanceUtility.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceUtility.h
#include "../../interface/IInterface.h"
#include "CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CInstanceUtility
	{

		//Begin section for atom::CInstanceUtility
		//TODO: Add attributes that you want preserved
		//End section for atom::CInstanceUtility



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static CObjectPtr CreateInstance(U32 type); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static CObjectPtr ObtainInstance(U64 name); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static bool InitiateInstance(CObjectPtr & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static bool ShutdownInstance(CObjectPtr & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U64 GetInstanceName(IInterface * value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U32 GetInstanceType(IInterface * value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static const char * GetInstanceDesc(IInterface * value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static CObjectPtr MakeObject(IInterface * nest); 



	};  //end class CInstanceUtility



} //end namespace atom



#endif

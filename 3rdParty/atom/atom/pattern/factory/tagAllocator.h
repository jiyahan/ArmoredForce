#ifndef TAGALLOCATOR_H
#define TAGALLOCATOR_H
//Begin section for file tagAllocator.h
//TODO: Add definitions that you want preserved
//End section for file tagAllocator.h
#include "../../utility/tool/CObjectPtr.h"


namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagAllocator
	{

		//Begin section for atom::tagAllocator
		//TODO: Add attributes that you want preserved
		//End section for atom::tagAllocator

		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 lower;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 upper;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr point;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~tagAllocator(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Clear(); 



	};  //end struct tagAllocator



} //end namespace atom



#endif

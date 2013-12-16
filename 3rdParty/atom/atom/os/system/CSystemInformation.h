#ifndef CSYSTEMINFORMATION_H
#define CSYSTEMINFORMATION_H
//Begin section for file CSystemInformation.h
//TODO: Add definitions that you want preserved
//End section for file CSystemInformation.h
#include "../../Common.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CSystemInformation
	{

		//Begin section for atom::CSystemInformation
		//TODO: Add attributes that you want preserved
		//End section for atom::CSystemInformation



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U32 GetProcessorCount(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U64 GetPhysicalMemorySize(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static U64 GetPhysicalMemoryFree(); 



	};  //end class CSystemInformation



} //end namespace atom



#endif

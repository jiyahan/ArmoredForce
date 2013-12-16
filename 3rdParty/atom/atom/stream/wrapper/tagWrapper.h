#ifndef TAGWRAPPER_H
#define TAGWRAPPER_H
//Begin section for file tagWrapper.h
//TODO: Add definitions that you want preserved
//End section for file tagWrapper.h
#include "../../interface/IStream.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	union tagWrapper
	{

		//Begin section for atom::tagWrapper
		//TODO: Add attributes that you want preserved
		//End section for atom::tagWrapper



		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void * u;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IStream * s;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IImportStream * i;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IExportStream * e;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagWrapper(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~tagWrapper(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Clear();



	};  //end union tagWrapper



} //end namespace atom



#endif

#ifndef CUTF8CHARSET_H
#define CUTF8CHARSET_H
//Begin section for file CUtf8Charset.h
//TODO: Add definitions that you want preserved
//End section for file CUtf8Charset.h
#include "../../Common.h"
#include "../stl/CU08Array.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CUtf8Charset
	{

		//Begin section for atom::CUtf8Charset
		//TODO: Add attributes that you want preserved
		//End section for atom::CUtf8Charset



		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static bool IsUtf8(const char * string); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			static size_t Utf8Length(const char * string); 

    
    
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static size_t Utf8Section(const char * string, CU08Array & section); 



    };  //end class CUtf8Charset



} //end namespace atom



#endif

#ifndef CAPPLELIBRARY_H
#define CAPPLELIBRARY_H
//Begin section for file CAppleLibrary.h
//TODO: Add definitions that you want preserved
//End section for file CAppleLibrary.h
#include "../../utility/stl/a_string.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAppleLibrary
	{

		//Begin section for atom::CAppleLibrary
		//TODO: Add attributes that you want preserved
		//End section for atom::CAppleLibrary

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void * handle;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			a_string locate;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAppleLibrary(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CAppleLibrary(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Open(const char * file); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Open(const wchar_t * file); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void * GetFunction(const char * name); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Close(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            // return utf8 charset as default;
			virtual a_string GetPath(); 



	};  //end class CAppleLibrary



} //end namespace atom



#endif

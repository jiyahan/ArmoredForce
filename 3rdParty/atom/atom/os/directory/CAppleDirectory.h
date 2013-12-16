#ifndef CAPPLEDIRECTORY_H
#define CAPPLEDIRECTORY_H
//Begin section for file CAppleDirectory.h
//TODO: Add definitions that you want preserved
//End section for file CAppleDirectory.h
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CAppleDirectory
	{

		//Begin section for atom::CAppleDirectory
		//TODO: Add attributes that you want preserved
		//End section for atom::CAppleDirectory

		// mac os only support utf-8 format file system, so, input ansi path will be 
		// converted to utf-8 format, and under apple os, all file and directory api
		// output will be also utf-8 format.

        // in our project, the input path under different platform can be different, 
        // we can check char * 's format: utf8 or multi-bytes, and convert to platform
        // accepted format.

        // in our project, the output under different platform will be the same, 
        // char * means utf8 charset, and wchar_t means unicode.

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			a_string path;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumFiles(const char * path, CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumFiles(const char * path, CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumDirectories(const char * path, CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumDirectories(const char * path, CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAppleDirectory(const char * path); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CAppleDirectory(const wchar_t * path); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~CAppleDirectory(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumFiles(CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumFiles(CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumDirectories(CStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void EnumDirectories(CWStringArray & files, bool sub_directory=true, bool absolute_path=true); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool CreateDirectory(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool RemoveDirectory(bool withfile=false); 



	};  //end class CAppleDirectory



} //end namespace atom



#endif

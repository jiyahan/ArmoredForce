#ifndef CWIN32DIRECTORY_H
#define CWIN32DIRECTORY_H
//Begin section for file CWin32Directory.h
//TODO: Add definitions that you want preserved
//End section for file CWin32Directory.h
#include "../../utility/stl/a_wstring.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"


namespace atom
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32Directory
    {

        //Begin section for atom::CWin32Directory
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32Directory

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_wstring path;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(const wchar_t * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(const wchar_t * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(const wchar_t * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(const wchar_t * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CWin32Directory(const char * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CWin32Directory(const wchar_t * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CWin32Directory(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool CreateDirectory(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool RemoveDirectory(bool withfile = false); 



    };  //end class CWin32Directory



} //end namespace atom



#endif

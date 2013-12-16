#ifndef CLINUXDIRECTORY_H
#define CLINUXDIRECTORY_H
//Begin section for file CLinuxDirectory.h
//TODO: Add definitions that you want preserved
//End section for file CLinuxDirectory.h
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/CStringArray.h"
#include "../../utility/stl/CWStringArray.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLinuxDirectory
    {

        //Begin section for atom::CLinuxDirectory
        //TODO: Add attributes that you want preserved
        //End section for atom::CLinuxDirectory

		// Linux ext2, ext3, ext4 file system support stream-style file name, that will be the nightmare, 
        // it does not have to use some constraint character set, so, input ansi path name will never been 
		// change, user should use the correct character set to visit directory,  unicode input will be 
        // convert to utf8 format, and output will be convert to utf8 or unicode ucs string.

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string path;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(const char * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumFiles(const char * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(const char * path, CStringArray  & files, bool sub_directory = false, bool absolute_path = false); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void EnumDirectories(const char * path, CWStringArray & files, bool sub_directory = false, bool absolute_path = false); 




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLinuxDirectory(const char * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLinuxDirectory(const wchar_t * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CLinuxDirectory(); 



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



    };  //end class CLinuxDirectory



} //end namespace atom



#endif

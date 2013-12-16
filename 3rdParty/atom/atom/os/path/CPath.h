#ifndef CPATH_H
#define CPATH_H
//Begin section for file CPath.h
//TODO: Add definitions that you want preserved
//End section for file CPath.h
#include "../../utility/stl/a_string.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CPath
    {

        //Begin section for atom::CPath
        //TODO: Add attributes that you want preserved
        //End section for atom::CPath

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string path;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CPath(const char * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CPath(const wchar_t * path); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CPath(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string GetFileName(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string GetFilePath(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool IsMatch(const char * wildcard); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool IsMatch(const wchar_t * wildcard); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            operator const char *(); 



    };  //end class CPath


}//end namespace atom


#endif

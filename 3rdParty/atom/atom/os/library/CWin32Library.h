#ifndef CWIN32LIBRARY_H
#define CWIN32LIBRARY_H
//Begin section for file CWin32Library.h
//TODO: Add definitions that you want preserved
//End section for file CWin32Library.h
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32Library
    {
        //Begin section for atom::CWin32Library
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32Library

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void * handle;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_wstring locate;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CWin32Library(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CWin32Library(); 



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



    };  //end class CWin32Library


}//end namespace atom


#endif

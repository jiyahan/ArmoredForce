#ifndef CWIN32SIGNAL_H
#define CWIN32SIGNAL_H
//Begin section for file CWin32Signal.h
//TODO: Add definitions that you want preserved
//End section for file CWin32Signal.h
#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32Signal
    {

        //Begin section for atom::CWin32Signal
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32Signal

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void * handle;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CWin32Signal(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            explicit CWin32Signal(const char * name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CWin32Signal(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Reset(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Awake(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Await(U64 timeout); 



    };  //end class CWin32Signal


}//end namespace atom


#endif

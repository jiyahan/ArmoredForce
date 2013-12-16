#ifndef CCALLSTACK_H
#define CCALLSTACK_H
//Begin section for file CCallStack.h
//TODO: Add definitions that you want preserved
//End section for file CCallStack.h
#include "../../utility/stl/a_string.h"


namespace atom
{


    
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CCallStack
    {

        //Begin section for atom::CCallStack
        //TODO: Add attributes that you want preserved
        //End section for atom::CCallStack



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool Initiate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Shutdown(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static int RecordCallStack(a_string & stack); 



    };  //end class CCallStack



} //end namespace atom



#endif

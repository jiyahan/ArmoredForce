#ifndef CLINUXSIGNAL_H
#define CLINUXSIGNAL_H
//Begin section for file CLinuxSignal.h
//TODO: Add definitions that you want preserved
//End section for file CLinuxSignal.h
#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLinuxSignal
    {

        //Begin section for atom::CLinuxSignal
        //TODO: Add attributes that you want preserved
        //End section for atom::CLinuxSignal

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool state;



            #ifdef __linux            
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            pthread_mutex_t region;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            pthread_cond_t  signal;
            #endif



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLinuxSignal(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            explicit CLinuxSignal(const char * name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CLinuxSignal(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Reset(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Awake(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Await(U64 timeout); 



    };  //end class CLinuxSignal


}//end namespace atom


#endif

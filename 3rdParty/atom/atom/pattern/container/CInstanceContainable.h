#ifndef CINSTANCECONTAINABLE_H
#define CINSTANCECONTAINABLE_H
//Begin section for file CInstanceContainable.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceContainable.h
#include "CInstanceContainableBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CInstanceContainable
    {

        //Begin section for atom::CInstanceContainable
        //TODO: Add attributes that you want preserved
        //End section for atom::CInstanceContainable

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection clog;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceContainableBind instances;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceContainable(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CInstanceContainable(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Insert(CObjectPtr & instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CObjectPtr Obtain(U64 instance_name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Obtain(CU64Array & instances); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Inside(U64 instance_name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 Amount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Remove(U64 instance_name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void RemoveAll(); 



    };  //end class CInstanceContainable



} //end namespace atom



#endif

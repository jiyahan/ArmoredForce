#ifndef CINSTANCELIFEWAKEREFERENCEX_H
#define CINSTANCELIFEWAKEREFERENCEX_H
//Begin section for file CInstanceLifeWakeReferenceX.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceLifeWakeReferenceX.h
#include "CInstanceLifeWakeReference.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/stl/CU64Array.h"




namespace atom
{



    
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CInstanceLifeWakeReferenceX
    {

        //Begin section for atom::CInstanceLifeWakeReferenceX
        //TODO: Add attributes that you want preserved
        //End section for atom::CInstanceLifeWakeReferenceX

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceLifeWakeReference instances[INSTANCES_QUEUE];




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceLifeWakeReferenceX(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CInstanceLifeWakeReferenceX(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Insert(U64 instance, CObjectPtr & receiver); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Remove(U64 instance, CObjectPtr & receiver); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            int Increase(U64 instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            int Decrease(U64 instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Clear(CObjectPtr & receiver); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            int GetReference(U64 instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void GetInstances(CU64Array & instances); 



    };  //end class CInstanceLifeWakeReferenceX



} //end namespace atom



#endif

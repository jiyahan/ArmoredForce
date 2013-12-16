#ifndef CINSTANCES_H
#define CINSTANCES_H
//Begin section for file CInstances.h
//TODO: Add definitions that you want preserved
//End section for file CInstances.h
#include "CInstancesBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/stl/CU64Array.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CInstances
    {

        //Begin section for atom::CInstances
        //TODO: Add attributes that you want preserved
        //End section for atom::CInstances

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstancesBind instances;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection section;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstances(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CInstances(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Insert(CReferencedObject * instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Inside(U64 name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CObjectPtr Obtain(U64 name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Obtain(CU64Array & indices); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 Amount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CReferencedObject * Remove(U64 name, bool & exist, bool force=false); 



    };  //end class CInstances



} //end namespace atom



#endif

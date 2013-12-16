#ifndef CIOPORTER_H
#define CIOPORTER_H
//Begin section for file CIOPorter.h
//TODO: Add definitions that you want preserved
//End section for file CIOPorter.h
#include "../../interface/IInterface.h"
#include "../memory/CStream.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CIOPorter : public IInterface
    {

        //Begin section for atom::CIOPorter
        //TODO: Add attributes that you want preserved
        //End section for atom::CIOPorter

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CStream stream;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CIOPorter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CIOPorter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * QueryInterface(U32 iid); 



    };  //end class CIOPorter


}//end namespace atom


#endif

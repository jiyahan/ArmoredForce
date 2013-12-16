#ifndef CMESSAGEQUEUE_H
#define CMESSAGEQUEUE_H
//Begin section for file CMessageQueue.h
//TODO: Add definitions that you want preserved
//End section for file CMessageQueue.h
#include "CMessageQueueLife.h"
#include "CMessageQueueController.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMessageQueue : public CReferencedObject
    {

        //Begin section for electron::CMessageQueue
        //TODO: Add attributes that you want preserved
        //End section for electron::CMessageQueue

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueLife life;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueController controller;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueue(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMessageQueue(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            const char * ToString(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * QueryInterface(U32 iid); 



    };  //end class CMessageQueue



} //end namespace electron



#endif

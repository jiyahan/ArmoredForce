#ifndef CMESSAGEQUEUECONTROLLERSET_H
#define CMESSAGEQUEUECONTROLLERSET_H
//Begin section for file CMessageQueueControllerSet.h
//TODO: Add definitions that you want preserved
//End section for file CMessageQueueControllerSet.h
#include "../Common.h"
#include "CMessageQueueControllerSetBind.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMessageQueueControllerSet
    {

        //Begin section for electron::CMessageQueueControllerSet
        //TODO: Add attributes that you want preserved
        //End section for electron::CMessageQueueControllerSet

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueControllerSetBind queue;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection section;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueControllerSet(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMessageQueueControllerSet(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Insert(CMessage * msg); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Obtain(CMessageQueueControllerSetBind & out); 



    };  //end class CMessageQueueControllerSet



} //end namespace electron



#endif

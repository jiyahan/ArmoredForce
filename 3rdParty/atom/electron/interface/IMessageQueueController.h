#ifndef IMESSAGEQUEUECONTROLLER_H
#define IMESSAGEQUEUECONTROLLER_H
//Begin section for file IMessageQueueController.h
//TODO: Add definitions that you want preserved
//End section for file IMessageQueueController.h
#include "../Common.h"
#include "../message/CMessage.h"
#include "../message/CMessageQueueControllerSetBind.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IMessageQueueController : public IEmbedInterface
    {

        //Begin section for electron::IMessageQueueController
        //TODO: Add attributes that you want preserved
        //End section for electron::IMessageQueueController



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Clear() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetQueueAmount(U32 amount) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 GetQueueAmount() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Insert(U64 id, CMessage * msg) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Obtain(U32 id, CMessageQueueControllerSetBind & out) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Repose(U32 id, U64 timeout) = 0; 



    };  //end class IMessageQueueController



} //end namespace electron



#endif

#ifndef CMESSAGEQUEUECONTROLLER_H
#define CMESSAGEQUEUECONTROLLER_H
//Begin section for file CMessageQueueController.h
//TODO: Add definitions that you want preserved
//End section for file CMessageQueueController.h
#include "../interface/IMessageQueueController.h"
#include "CMessageQueueControllerSet.h"
#include "CMessage.h"
#include "CMessageQueueControllerSetBind.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMessageQueueController : public IMessageQueueController
    {

        //Begin section for electron::CMessageQueueController
        //TODO: Add attributes that you want preserved
        //End section for electron::CMessageQueueController

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueControllerSet queues[MAX_MESSAGE_QUEUE_CONTROLLER_SET];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CSignal signal[MAX_MESSAGE_QUEUE_CONTROLLER_SET];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U32 amount;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMessageQueueController(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMessageQueueController(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetNest(IInterface * nest); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Clear(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetQueueAmount(U32 amount); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 GetQueueAmount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Insert(U64 id, CMessage * msg); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Obtain(U32 id, CMessageQueueControllerSetBind & out); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Repose(U32 id, U64 timeout); 



    };  //end class CMessageQueueController



} //end namespace electron



#endif

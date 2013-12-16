#ifndef CCONNECTIONSCHEDULER_H
#define CCONNECTIONSCHEDULER_H
//Begin section for file CConnectionScheduler.h
//TODO: Add definitions that you want preserved
//End section for file CConnectionScheduler.h
#include "../Common.h"
#include "CConnectionSchedulerSingletonBind.h"
#include "CConnectionSchedulerLife.h"
#include "CConnectionSchedulerEventReceiver.h"
#include "CConnectionSchedulerMultiThread.h"
#include "CConnectionSchedulerController.h"
#include "CConnectionSchedulerAliasContainer.h"
#include "../message/CMessage.h"
#include "../stub/tagFlowStatistics.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectionScheduler : public IReferencedObject, public CConnectionSchedulerSingletonBind
    {

        //Begin section for electron::CConnectionScheduler
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectionScheduler

        private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CReference counter;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CEventEmitter emitter;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceContainerListener listener;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceContainer container;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerLife life;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerEventReceiver receiver;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerMultiThread threads;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerController controller;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerAliasContainer alias;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionScheduler(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectionScheduler(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Initiate(U32 thread_amount=1); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Shutdown(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 Listen(const char * address, U16 port, U32 io_model, U64 message_queue); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 Connect(const char * address, U16 port, U32 io_model, U64 message_queue); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Send(U64 connector, CMessage * message); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Close(U64 connection_name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 GetEventSpace(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool GetStatistias(U64 connector, tagFlowStatistics & origin, tagFlowStatistics & actual, U64 & largest); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetName(U64 name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 GetName(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetType(U32 type); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 GetType(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual const char * ToString(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CConnectionScheduler



} //end namespace electron



#endif

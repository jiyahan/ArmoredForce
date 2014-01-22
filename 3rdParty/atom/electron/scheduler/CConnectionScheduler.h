#ifndef CCONNECTIONSCHEDULER_H
#define CCONNECTIONSCHEDULER_H
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



    class CConnectionScheduler : public IReferencedObject, public CConnectionSchedulerSingletonBind
    {


        private:


			CReference counter;



            CEventEmitter emitter;



            CInstanceContainerListener listener;



            CInstanceContainer container;



            CConnectionSchedulerLife life;



            CConnectionSchedulerEventReceiver receiver;



            CConnectionSchedulerMultiThread threads;



            CConnectionSchedulerController controller;



            CConnectionSchedulerAliasContainer alias;




        public:

            CConnectionScheduler(); 



            virtual ~CConnectionScheduler(); 



            bool Initiate(U32 thread_amount=1); 



            bool Shutdown(); 



            U64 Listen(const char * address, U16 port, U32 io_model, U64 message_queue); 



            U64 Connect(const char * address, U16 port, U32 io_model, U64 message_queue); 



            bool Send(U64 connector, CMessage * message); 



            bool Close(U64 connection_name); 



            U64 GetEventSpace(); 



            bool GetStatistias(U64 connector, tagFlowStatistics & origin, tagFlowStatistics & actual, U64 & largest); 



            virtual void SetName(U64 name); 



            virtual U64 GetName(); 



            virtual void SetType(U32 type); 



            virtual U32 GetType(); 



            virtual const char * ToString(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CConnectionScheduler



} //end namespace electron



#endif

#ifndef CCONNECTIONSCHEDULERCONTROLLER_H
#define CCONNECTIONSCHEDULERCONTROLLER_H
#include "../Common.h"
#include "../message/CMessage.h"
#include "../interface/IConnectionSchedulerController.h"
#include "CConnectionSchedulerControllerIndicesBind.h"
#include "CConnectionSchedulerControllerListenerBind.h"



namespace electron
{



    class CConnectionSchedulerController : public IConnectionSchedulerController
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            U32 amount;



            U64 inner_space;



            U64 outer_space;



            CConnectionSchedulerControllerIndicesBind connectors[MAX_SCHEDULER_WORKER_THREAD];



            CConnectionSchedulerControllerIndicesBind disconnect[MAX_SCHEDULER_WORKER_THREAD];



            CConnectionSchedulerControllerListenerBind listener;




        public:

            CConnectionSchedulerController(); 



            virtual ~CConnectionSchedulerController(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



            virtual void Retrieve(U32 index); 



            virtual U64 GetSpace(); 



            virtual U64 Listen(const char * address, U16 port, U32 io_model, U64 message_queue); 



            virtual U64 Connect(const char * address, U16 port, U32 io_model, U64 message_queue); 



            virtual bool Send(U64 connector, CMessage * message); 



            virtual bool Close(U64 connection_name); 



            virtual void OnConnectionLose(U64 name); 



            virtual bool OnConnectionOpen(U64 listener, U64 connector); 



            virtual void OnReceive(U64 connector); 



    };  //end class CConnectionSchedulerController



} //end namespace electron



#endif

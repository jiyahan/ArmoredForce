#ifndef CMESSAGEQUEUECONTROLLER_H
#define CMESSAGEQUEUECONTROLLER_H
#include "../interface/IMessageQueueController.h"
#include "CMessageQueueControllerSet.h"
#include "CMessage.h"
#include "CMessageQueueControllerSetBind.h"



namespace electron
{



    class CMessageQueueController : public IMessageQueueController
    {


        private:


            IInterface * nest;



            CMessageQueueControllerSet queues[MAX_MESSAGE_QUEUE_CONTROLLER_SET];



            CSignal signal[MAX_MESSAGE_QUEUE_CONTROLLER_SET];



            U32 amount;




        public:

            CMessageQueueController(); 



            virtual ~CMessageQueueController(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Clear(); 



            virtual void SetQueueAmount(U32 amount); 



            virtual U32 GetQueueAmount(); 



            virtual bool Insert(U64 id, CMessage * msg); 



            virtual bool Obtain(U32 id, CMessageQueueControllerSetBind & out); 



            virtual void Repose(U32 id, U64 timeout); 



    };  //end class CMessageQueueController



} //end namespace electron



#endif

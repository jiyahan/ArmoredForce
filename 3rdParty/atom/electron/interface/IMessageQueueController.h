#ifndef IMESSAGEQUEUECONTROLLER_H
#define IMESSAGEQUEUECONTROLLER_H
#include "../Common.h"
#include "../message/CMessage.h"
#include "../message/CMessageQueueControllerSetBind.h"



namespace electron
{



    class IMessageQueueController : public IEmbedInterface
    {




        public:

            virtual void Clear() = 0; 



            virtual void SetQueueAmount(U32 amount) = 0; 



            virtual U32 GetQueueAmount() = 0; 



            virtual bool Insert(U64 id, CMessage * msg) = 0; 



            virtual bool Obtain(U32 id, CMessageQueueControllerSetBind & out) = 0; 



            virtual void Repose(U32 id, U64 timeout) = 0; 



    };  //end class IMessageQueueController



} //end namespace electron



#endif

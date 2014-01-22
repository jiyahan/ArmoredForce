#ifndef ICONNECTIONSCHEDULERCONTROLLER_H
#define ICONNECTIONSCHEDULERCONTROLLER_H
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{



    class IConnectionSchedulerController : public IEmbedInterface
    {




        public:

            virtual bool Initiate() = 0; 



            virtual bool Shutdown() = 0; 



            virtual void Retrieve(U32 index) = 0; 



            virtual U64 GetSpace() = 0; 



            virtual U64 Listen(const char * address, U16 port, U32 io_model, U64 message_queue) = 0; 



            virtual U64 Connect(const char * address, U16 port, U32 io_model, U64 message_queue) = 0; 



            virtual bool Send(U64 connector, CMessage * message) = 0; 



            virtual bool Close(U64 connection_name) = 0; 



            virtual void OnConnectionLose(U64 name) = 0; 



            virtual bool OnConnectionOpen(U64 listener, U64 connector) = 0; 



            virtual void OnReceive(U64 connector) = 0; 



    };  //end class IConnectionSchedulerController



} //end namespace electron



#endif

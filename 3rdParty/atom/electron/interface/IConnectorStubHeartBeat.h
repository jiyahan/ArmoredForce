#ifndef ICONNECTORSTUBHEARTBEAT_H
#define ICONNECTORSTUBHEARTBEAT_H
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{
    


    class IConnectorStubHeartBeat : public IEmbedInterface
    {




        public:

            virtual void OnMessage(CMessage * message) = 0; 



            virtual U64 OnProcess(U64 now) = 0; 



            virtual void Reset() = 0; 



    };  //end class IConnectorStubHeartBeat



} //end namespace electron



#endif

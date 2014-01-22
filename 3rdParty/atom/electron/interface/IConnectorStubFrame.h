#ifndef ICONNECTORSTUBFRAME_H
#define ICONNECTORSTUBFRAME_H
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{
    


    class IConnectorStubFrame : public IEmbedInterface
    {




        public:

            virtual bool Open(U64 connector, U64 msg_queue) = 0; 



            virtual bool Shut() = 0; 



            virtual bool Read(U64 time) = 0; 



            virtual bool Send(CMessage * msg) = 0;



            virtual U64 LastReceive() = 0;



    };  //end class IConnectorStubFrame



} //end namespace electron



#endif

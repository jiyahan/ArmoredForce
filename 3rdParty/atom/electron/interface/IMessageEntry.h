#ifndef IMESSAGEENTRY_H
#define IMESSAGEENTRY_H
#include "../Common.h"



namespace electron
{



    class IMessageEntry : public IEmbedInterface
    {




        public:

            virtual void SetCommandID(U16 value) = 0; 



            virtual U16 GetCommandID() = 0; 



            virtual void SetConnector(U64 value) = 0; 



            virtual U64 GetConnector() = 0; 



            virtual void Clear() = 0; 



    };  //end class IMessageEntry



} //end namespace electron



#endif

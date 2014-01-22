#ifndef CMESSAGEENTRY_H
#define CMESSAGEENTRY_H
#include "../interface/IMessageEntry.h"



namespace electron
{



    class CMessageEntry : public IMessageEntry
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            U16 command;



            U64 connect;




        public:

            CMessageEntry(); 



            virtual ~CMessageEntry(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void SetCommandID(U16 value); 



            virtual U16 GetCommandID(); 



            virtual void SetConnector(U64 value); 



            virtual U64 GetConnector(); 



            virtual void Clear(); 



    };  //end class CMessageEntry



} //end namespace electron



#endif

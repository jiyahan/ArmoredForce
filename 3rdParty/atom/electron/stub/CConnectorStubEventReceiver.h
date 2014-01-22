#ifndef CCONNECTORSTUBEVENTRECEIVER_H
#define CCONNECTORSTUBEVENTRECEIVER_H
#include "../Common.h"



namespace electron
{
    


    class CConnectorStubEventReceiver : public IEventReceiver
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CConnectorStubEventReceiver(); 



            virtual ~CConnectorStubEventReceiver(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool OnEvent(const tagEvent & event); 



    };  //end class CConnectorStubEventReceiver



} //end namespace electron



#endif

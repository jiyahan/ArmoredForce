#ifndef CCONNECTIONSCHEDULEREVENTRECEIVER_H
#define CCONNECTIONSCHEDULEREVENTRECEIVER_H
#include "../Common.h"



namespace electron
{



    class CConnectionSchedulerEventReceiver : public IEventReceiver
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CConnectionSchedulerEventReceiver(); 



            virtual ~CConnectionSchedulerEventReceiver(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool OnEvent(const tagEvent & event); 



    };  //end class CConnectionSchedulerEventReceiver



} //end namespace electron



#endif

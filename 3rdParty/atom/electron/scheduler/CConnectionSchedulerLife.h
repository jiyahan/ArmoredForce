#ifndef CCONNECTIONSCHEDULERLIFE_H
#define CCONNECTIONSCHEDULERLIFE_H
#include "../Common.h"



namespace electron
{



    class CConnectionSchedulerLife : public IInstanceLife
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CConnectionSchedulerLife(); 



            virtual ~CConnectionSchedulerLife(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



    };  //end class CConnectionSchedulerLife



} //end namespace electron



#endif

#ifndef CCONNECTIONSCHEDULERMULTITHREAD_H
#define CCONNECTIONSCHEDULERMULTITHREAD_H
#include "../Common.h"
#include "CConnectionSchedulerMultiThreadWorker.h"



namespace electron
{



    class CConnectionSchedulerMultiThread : public IMultiThreadControl
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            CConnectionSchedulerMultiThreadWorker worker[MAX_SCHEDULER_WORKER_THREAD];



            U32 amount;




        public:

            CConnectionSchedulerMultiThread(); 



            virtual ~CConnectionSchedulerMultiThread(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool OnBegin(); 



            virtual bool OnClose(); 



            virtual void OnAwake(); 



            virtual bool OnBegin(U32 index); 



            virtual bool OnClose(U32 index); 



            virtual void OnAwake(U32 index); 



            virtual void SetThreadAmount(U32 value); 



            virtual U32 GetThreadAmount(); 



    };  //end class CConnectionSchedulerMultiThread



} //end namespace electron



#endif

#ifndef CCONNECTIONSCHEDULERMULTITHREADWORKER_H
#define CCONNECTIONSCHEDULERMULTITHREADWORKER_H
#include "../Common.h"



namespace electron
{



    class CConnectionSchedulerMultiThreadWorker : public CThread
    {


        private:


            U32 serial;



            bool active;



            CObjectPtr object;



            CSignal signal;




        public:

            CConnectionSchedulerMultiThreadWorker(); 



            virtual ~CConnectionSchedulerMultiThreadWorker(); 



            virtual U32 Run(); 



            virtual bool OnThreadBegin(); 



            virtual bool OnThreadClose(); 



            void SetObject(CObjectPtr & value); 



            void SetActive(bool value); 



            void SetAwaken(); 



            void SetSerial(U32 serial); 



            bool GetActive();



    };  //end class CConnectionSchedulerMultiThreadWorker



} //end namespace electron



#endif

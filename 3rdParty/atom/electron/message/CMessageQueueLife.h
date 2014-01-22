#ifndef CMESSAGEQUEUELIFE_H
#define CMESSAGEQUEUELIFE_H
#include "../Common.h"



namespace electron
{



    class CMessageQueueLife : public IInstanceLife
    {


        private:


            IInterface * nest;




        public:

            CMessageQueueLife(); 



            virtual ~CMessageQueueLife(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



    };  //end class CMessageQueueLife



} //end namespace electron



#endif

#ifndef CMESSAGEQUEUECONTROLLERSET_H
#define CMESSAGEQUEUECONTROLLERSET_H
#include "../Common.h"
#include "CMessageQueueControllerSetBind.h"



namespace electron
{



    class CMessageQueueControllerSet
    {


        private:


            CMessageQueueControllerSetBind queue;



            CCriticalSection section;




        public:

            CMessageQueueControllerSet(); 



            virtual ~CMessageQueueControllerSet(); 



            bool Insert(CMessage * msg); 



            bool Obtain(CMessageQueueControllerSetBind & out); 



    };  //end class CMessageQueueControllerSet



} //end namespace electron



#endif

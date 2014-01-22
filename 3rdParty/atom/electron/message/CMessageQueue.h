#ifndef CMESSAGEQUEUE_H
#define CMESSAGEQUEUE_H
#include "CMessageQueueLife.h"
#include "CMessageQueueController.h"



namespace electron
{



    class CMessageQueue : public CReferencedObject
    {


        private:


            CMessageQueueLife life;



            CMessageQueueController controller;




        public:

            CMessageQueue(); 



            virtual ~CMessageQueue(); 



            const char * ToString(); 



            IInterface * QueryInterface(U32 iid); 



    };  //end class CMessageQueue



} //end namespace electron



#endif

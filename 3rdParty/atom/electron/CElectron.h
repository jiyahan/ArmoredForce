#ifndef CELECTRON_H
#define CELECTRON_H
#include "Common.h"
#include "allocator/CElectronAllocator.h"
#include "scheduler/CConnectionScheduler.h"

#include "stub/CConnectorStub.h"
#include "stub/tagFlowStatistics.h"

#include "message/CMessage.h"
#include "message/CMessageQueue.h"
#include "message/CMessageAllocator.h"

#include "interface/IConnectionSchedulerController.h"
#include "interface/IConnectorStubFrame.h"
#include "interface/IConnectorStubHeartBeat.h"
#include "interface/IConnectorStubStatistics.h"
#include "interface/IMessageEntry.h"
#include "interface/IMessageQueueController.h"

#include "enumeration/EVENT_ID.h"
#include "enumeration/INTERFACE_ID.h"
#include "enumeration/MESSAGE_ID.h"
#include "enumeration/OBJECT_ID.h"
#include "enumeration/SINGLETON_OBJECT_ID.h"



namespace electron
{



    class CElectron
    {


        private:


            static bool active;




        public:

            static void Presetup(); 



            static bool Initiate(U32 thread_amount = 1); 



            static bool Shutdown(); 



            static void Destruct(); 



            static bool IsActive(); 



    };  //end class CElectron



} //end namespace electron



#endif

#ifndef CELECTRON_H
#define CELECTRON_H
//Begin section for file CElectron.h
//TODO: Add definitions that you want preserved
//End section for file CElectron.h
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



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CElectron
    {

        //Begin section for electron::CElectron
        //TODO: Add attributes that you want preserved
        //End section for electron::CElectron

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool active;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Presetup(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool Initiate(U32 thread_amount = 1); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool Shutdown(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Destruct(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool IsActive(); 



    };  //end class CElectron



} //end namespace electron



#endif

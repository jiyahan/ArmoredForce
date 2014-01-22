#ifndef CCONNECTORSTUB_H
#define CCONNECTORSTUB_H
#include "CConnectorStubEventReceiver.h"
#include "CConnectorStubFrame.h"
#include "CConnectorStubMaintainable.h"
#include "CConnectorStubLife.h"
#include "CConnectorStubHeartBeat.h"
#include "CConnectorStubStatistics.h"



namespace electron
{



    class CConnectorStub : public CReferencedObject
    {


        private:


            CConnectorStubEventReceiver receiver;



            CEventDirectEmitter emitter;



            CConnectorStubFrame frame;



            CConnectorStubMaintainable maintain;



            CConnectorStubLife life;



            CConnectorStubHeartBeat heartbeat;



            CConnectorStubStatistics statistics;




        public:

            CConnectorStub(); 



            virtual ~CConnectorStub(); 



            const char * ToString(); 



            IInterface * QueryInterface(U32 iid); 



    };  //end class CConnectorStub



} //end namespace electron



#endif

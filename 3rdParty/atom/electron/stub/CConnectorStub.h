#ifndef CCONNECTORSTUB_H
#define CCONNECTORSTUB_H
//Begin section for file CConnectorStub.h
//TODO: Add definitions that you want preserved
//End section for file CConnectorStub.h
#include "CConnectorStubEventReceiver.h"
#include "CConnectorStubFrame.h"
#include "CConnectorStubMaintainable.h"
#include "CConnectorStubLife.h"
#include "CConnectorStubHeartBeat.h"
#include "CConnectorStubStatistics.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectorStub : public CReferencedObject
    {

        //Begin section for electron::CConnectorStub
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectorStub

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubEventReceiver receiver;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CEventDirectEmitter emitter;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubFrame frame;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubMaintainable maintain;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubLife life;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubHeartBeat heartbeat;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubStatistics statistics;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStub(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectorStub(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            const char * ToString(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * QueryInterface(U32 iid); 



    };  //end class CConnectorStub



} //end namespace electron



#endif

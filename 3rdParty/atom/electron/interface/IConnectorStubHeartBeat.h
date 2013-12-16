#ifndef ICONNECTORSTUBHEARTBEAT_H
#define ICONNECTORSTUBHEARTBEAT_H
//Begin section for file IConnectorStubHeartBeat.h
//TODO: Add definitions that you want preserved
//End section for file IConnectorStubHeartBeat.h
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IConnectorStubHeartBeat : public IEmbedInterface
    {

        //Begin section for electron::IConnectorStubHeartBeat
        //TODO: Add attributes that you want preserved
        //End section for electron::IConnectorStubHeartBeat



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnMessage(CMessage * message) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 OnProcess(U64 now) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Reset() = 0; 



    };  //end class IConnectorStubHeartBeat



} //end namespace electron



#endif

#ifndef ICONNECTIONSCHEDULERCONTROLLER_H
#define ICONNECTIONSCHEDULERCONTROLLER_H
//Begin section for file IConnectionSchedulerController.h
//TODO: Add definitions that you want preserved
//End section for file IConnectionSchedulerController.h
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IConnectionSchedulerController : public IEmbedInterface
    {

        //Begin section for electron::IConnectionSchedulerController
        //TODO: Add attributes that you want preserved
        //End section for electron::IConnectionSchedulerController



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Initiate() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Shutdown() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Retrieve(U32 index) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 GetSpace() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Listen(const char * address, U16 port, U32 io_model, U64 message_queue) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Connect(const char * address, U16 port, U32 io_model, U64 message_queue) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Send(U64 connector, CMessage * message) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Close(U64 connection_name) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnConnectionLose(U64 name) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnConnectionOpen(U64 listener, U64 connector) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnReceive(U64 connector) = 0; 



    };  //end class IConnectionSchedulerController



} //end namespace electron



#endif

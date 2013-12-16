#ifndef ICONNECTORSTUBFRAME_H
#define ICONNECTORSTUBFRAME_H
//Begin section for file IConnectorStubFrame.h
//TODO: Add definitions that you want preserved
//End section for file IConnectorStubFrame.h
#include "../Common.h"
#include "../message/CMessage.h"



namespace electron
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IConnectorStubFrame : public IEmbedInterface
    {

        //Begin section for electron::IConnectorStubFrame
        //TODO: Add attributes that you want preserved
        //End section for electron::IConnectorStubFrame



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Open(U64 connector, U64 msg_queue) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Shut() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Read(U64 time) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Send(CMessage * msg) = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 LastReceive() = 0;



    };  //end class IConnectorStubFrame



} //end namespace electron



#endif

#ifndef IMESSAGEENTRY_H
#define IMESSAGEENTRY_H
//Begin section for file IMessageEntry.h
//TODO: Add definitions that you want preserved
//End section for file IMessageEntry.h
#include "../Common.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IMessageEntry : public IEmbedInterface
    {

        //Begin section for electron::IMessageEntry
        //TODO: Add attributes that you want preserved
        //End section for electron::IMessageEntry



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetCommandID(U16 value) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U16 GetCommandID() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetConnector(U64 value) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 GetConnector() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Clear() = 0; 



    };  //end class IMessageEntry



} //end namespace electron



#endif

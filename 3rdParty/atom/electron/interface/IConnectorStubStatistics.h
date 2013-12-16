#ifndef ICONNECTORSTUBSTATISTICS_H
#define ICONNECTORSTUBSTATISTICS_H
//Begin section for file IConnectorStubStatistics.h
//TODO: Add definitions that you want preserved
//End section for file IConnectorStubStatistics.h
#include "../Common.h"
#include "../stub/tagFlowStatistics.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IConnectorStubStatistics : public IEmbedInterface
    {

        //Begin section for electron::IConnectorStubStatistics
        //TODO: Add attributes that you want preserved
        //End section for electron::IConnectorStubStatistics



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnReadFrame(U64 origin, U64 reduce) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnSendFrame(U64 origin, U64 reduce) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnLongFrame(U64 value) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void GetStatistics(U64 & largest, tagFlowStatistics & plain, tagFlowStatistics & final) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Reset() = 0; 



    };  //end class IConnectorStubStatistics



} //end namespace electron



#endif

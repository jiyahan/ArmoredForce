#ifndef TAGFLOWSTATISTICS_H
#define TAGFLOWSTATISTICS_H
//Begin section for file tagFlowStatistics.h
//TODO: Add definitions that you want preserved
//End section for file tagFlowStatistics.h
#include "../Common.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagFlowStatistics
    {

        //Begin section for electron::tagFlowStatistics
        //TODO: Add attributes that you want preserved
        //End section for electron::tagFlowStatistics



        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 send_bytes;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 send_frame;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 read_bytes;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 read_frame;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagFlowStatistics() : 
            send_bytes(0),send_frame(0),read_bytes(0),read_frame(0)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagFlowStatistics()
            {
                //TODO Auto-generated method stub
            }



    };  //end struct tagFlowStatistics



} //end namespace electron



#endif

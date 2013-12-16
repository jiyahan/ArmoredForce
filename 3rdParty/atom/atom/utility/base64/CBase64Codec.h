#ifndef CBASE64CODEC_H
#define CBASE64CODEC_H
//Begin section for file CBase64Codec.h
//TODO: Add definitions that you want preserved
//End section for file CBase64Codec.h
#include "../../os/memory/CMemory.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CBase64Codec
    {

        //Begin section for atom::CBase64Codec
        //TODO: Add attributes that you want preserved
        //End section for atom::CBase64Codec



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool Encode(CMemory & source, CMemory & target); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static bool Decode(CMemory & source, CMemory & target); 



    };  //end class CBase64Codec



} //end namespace atom



#endif

#ifndef CBASE64CODEC_H
#define CBASE64CODEC_H
#include "../../os/memory/CMemory.h"



namespace atom
{



    class CBase64Codec
    {




        public:

            static bool Encode(CMemory & source, CMemory & target); 



            static bool Decode(CMemory & source, CMemory & target); 



    };  //end class CBase64Codec



} //end namespace atom



#endif

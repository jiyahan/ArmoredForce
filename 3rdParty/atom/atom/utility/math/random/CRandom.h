#ifndef CRANDOM_H
#define CRANDOM_H
#include "../../../Common.h"



namespace atom
{



    class CRandom
    {




        public:

            static void Initiate(); 



            inline static int Random(); 



    };  //end class CRandom


}//end namespace atom


int atom::CRandom::Random() 
{
    return( rand() / 2 + rand() / 2 );
}

#endif

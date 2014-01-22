#ifndef CCALLSTACK_H
#define CCALLSTACK_H
#include "../../utility/stl/a_string.h"


namespace atom
{


    
    class CCallStack
    {




        public:

            static bool Initiate(); 



            static void Shutdown(); 



            static int RecordCallStack(a_string & stack); 



    };  //end class CCallStack



} //end namespace atom



#endif

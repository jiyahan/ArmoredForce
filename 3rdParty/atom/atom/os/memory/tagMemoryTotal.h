#ifndef TAGMEMORYTOTAL_H
#define TAGMEMORYTOTAL_H
#include "../../Common.h"



namespace atom
{



    struct tagMemoryTotal
    {




        public:


            U64 a_count;



            U64 r_count;



            U64 m_count;



            inline tagMemoryTotal(); 



            inline ~tagMemoryTotal(); 



    };  //end struct tagMemoryTotal


}//end namespace atom


atom::tagMemoryTotal::tagMemoryTotal() : 
a_count(0),r_count(0),m_count(0)
{
}

atom::tagMemoryTotal::~tagMemoryTotal() 
{
}

#endif

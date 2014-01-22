#ifndef TAGMEMORYTOTALS_H
#define TAGMEMORYTOTALS_H
#include "tagMemoryTotal.h"



namespace atom
{



     struct tagMemoryTotals
     {


         public:


             tagMemoryTotal stages[MEMORY_FRAGMENT_QUEUE];




         public:

             inline tagMemoryTotals(); 



             inline ~tagMemoryTotals(); 



     };  //end class tagMemoryTotals


}//end namespace atom


atom::tagMemoryTotals::tagMemoryTotals() 
{
}

atom::tagMemoryTotals::~tagMemoryTotals() 
{
}

#endif

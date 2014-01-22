#ifndef TAGMEMORYCOUNTS_H
#define TAGMEMORYCOUNTS_H
#include "tagMemoryCount.h"



namespace atom
{



     struct tagMemoryCounts
     {




         public:


             tagMemoryCount stages[MEMORY_FRAGMENT_QUEUE];



             inline tagMemoryCounts(); 



             inline ~tagMemoryCounts(); 



     };  //end struct tagMemoryCounts


}//end namespace atom


atom::tagMemoryCounts::tagMemoryCounts() 
{
}

atom::tagMemoryCounts::~tagMemoryCounts() 
{
}

#endif

#ifndef CMEMORYSCHEDULERSINGLETONBIND_H
#define CMEMORYSCHEDULERSINGLETONBIND_H
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{


    class CMemoryScheduler;
    typedef CSingleton<CMemoryScheduler> CMemorySchedulerSingletonBind;

}//end namespace atom


#endif

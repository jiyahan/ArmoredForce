#ifndef CMEMORYSCHEDULERSINGLETONBIND_H
#define CMEMORYSCHEDULERSINGLETONBIND_H
//Begin section for file CMemorySchedulerSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CMemorySchedulerSingletonBind.h
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{


    class CMemoryScheduler;
    typedef CSingleton<CMemoryScheduler> CMemorySchedulerSingletonBind;

}//end namespace atom


#endif

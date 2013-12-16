#ifndef CMESSAGEALLOCATORSINGLETONBIND_H
#define CMESSAGEALLOCATORSINGLETONBIND_H
//Begin section for file CMessageAllocatorSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CMessageAllocatorSingletonBind.h
#include "../Common.h"



namespace electron
{



    class CMessageAllocator;
    typedef CSingleton<CMessageAllocator> CMessageAllocatorSingletonBind;



} //end namepace electron



#endif

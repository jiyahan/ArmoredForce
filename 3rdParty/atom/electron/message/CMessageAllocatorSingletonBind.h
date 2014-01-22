#ifndef CMESSAGEALLOCATORSINGLETONBIND_H
#define CMESSAGEALLOCATORSINGLETONBIND_H
#include "../Common.h"



namespace electron
{



    class CMessageAllocator;
    typedef CSingleton<CMessageAllocator> CMessageAllocatorSingletonBind;



} //end namepace electron



#endif

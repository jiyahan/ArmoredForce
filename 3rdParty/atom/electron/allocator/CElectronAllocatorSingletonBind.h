#ifndef CELECTRONALLOCATORSINGLETONBIND_H
#define CELECTRONALLOCATORSINGLETONBIND_H
//Begin section for file CElectronAllocatorSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CElectronAllocatorSingletonBind.h
#include "../Common.h"



namespace electron
{



    class CElectronAllocator;
    typedef CSingleton<CElectronAllocator> CElectronAllocatorSingletonBind;



} //end namespace electron



#endif

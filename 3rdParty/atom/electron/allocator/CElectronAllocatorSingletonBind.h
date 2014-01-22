#ifndef CELECTRONALLOCATORSINGLETONBIND_H
#define CELECTRONALLOCATORSINGLETONBIND_H
#include "../Common.h"



namespace electron
{



    class CElectronAllocator;
    typedef CSingleton<CElectronAllocator> CElectronAllocatorSingletonBind;



} //end namespace electron



#endif

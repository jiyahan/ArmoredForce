#ifndef CMAINTAINERSINGLETONBIND_H
#define CMAINTAINERSINGLETONBIND_H
#include "../pattern/singleton/CSingleton.h"



namespace atom
{
    
    class CMaintainer;
    typedef CSingleton<CMaintainer> CMaintainerSingletonBind;


} //end namespace atom



#endif

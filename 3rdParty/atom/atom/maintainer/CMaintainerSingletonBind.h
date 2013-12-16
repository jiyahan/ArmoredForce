#ifndef CMAINTAINERSINGLETONBIND_H
#define CMAINTAINERSINGLETONBIND_H
//Begin section for file CMaintainerSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CMaintainerSingletonBind.h
#include "../pattern/singleton/CSingleton.h"



namespace atom
{
    
    class CMaintainer;
    typedef CSingleton<CMaintainer> CMaintainerSingletonBind;


} //end namespace atom



#endif

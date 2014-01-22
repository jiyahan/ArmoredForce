#ifndef CCRITICALSECTION_H
#define CCRITICALSECTION_H
#include "CWin32CriticalSection.h"
#include "CLinuxCriticalSection.h"
#include "CAppleCriticalSection.h"


namespace atom
{


    #ifdef _WIN32
    typedef CWin32CriticalSection CCriticalSection ;
    #endif

    #ifdef __linux
    typedef CLinuxCriticalSection CCriticalSection ;
    #endif

    #ifdef __APPLE__
    typedef CAppleCriticalSection CCriticalSection ;
    #endif


}//end namespace atom


#endif

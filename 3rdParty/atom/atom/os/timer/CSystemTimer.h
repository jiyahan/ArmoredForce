#ifndef CSYSTEMTIMER_H
#define CSYSTEMTIMER_H
#include "CWin32SystemTimer.h"
#include "CLinuxSystemTimer.h"
#include "CAppleSystemTimer.h"


namespace atom
{


    #ifdef _WIN32
    typedef CWin32SystemTimer CSystemTimer ;
    #endif

    #ifdef __linux
    typedef CLinuxSystemTimer CSystemTimer ;
    #endif

    #ifdef __APPLE__
    typedef CAppleSystemTimer CSystemTimer ;
    #endif


}//end namespace atom


#endif

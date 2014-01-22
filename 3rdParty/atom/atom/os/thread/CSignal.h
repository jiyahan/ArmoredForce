#ifndef CSIGNAL_H
#define CSIGNAL_H
#include "CWin32Signal.h"
#include "CLinuxSignal.h"
#include "CAppleSignal.h"


namespace atom
{


    #ifdef _WIN32
    typedef CWin32Signal CSignal ;
    #endif

    #ifdef __linux
    typedef CLinuxSignal CSignal ;
    #endif

    #ifdef __APPLE__
    typedef CAppleSignal CSignal ;
    #endif


}//end namespace atom


#endif

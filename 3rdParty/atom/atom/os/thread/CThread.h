#ifndef CTHREAD_H
#define CTHREAD_H
#include "CWin32Thread.h"
#include "CLinuxThread.h"
#include "CAppleThread.h"


namespace atom
{


    #ifdef _WIN32
    typedef CWin32Thread CThread ;
    #endif

    #ifdef __linux
    typedef CLinuxThread CThread ;
    #endif

    #ifdef __APPLE__
    typedef CAppleThread CThread ;
    #endif


}//end namespace atom


#endif

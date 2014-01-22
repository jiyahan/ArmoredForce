#ifndef CMILISECONDTIMER_H
#define CMILISECONDTIMER_H
#include "CWin32MilisecondTimer.h"
#include "CLinuxMilisecondTimer.h"
#include "CAppleMilisecondTimer.h"



namespace atom
{


    #ifdef _WIN32
    typedef CWin32MilisecondTimer CMilisecondTimer ;
    #endif

    #ifdef __linux
    typedef CLinuxMilisecondTimer CMilisecondTimer ;
    #endif

    #ifdef __APPLE__
    typedef CAppleMilisecondTimer CMilisecondTimer ;
    #endif


}//end namespace atom


#endif

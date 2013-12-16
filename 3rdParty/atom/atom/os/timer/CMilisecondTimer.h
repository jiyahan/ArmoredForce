#ifndef CMILISECONDTIMER_H
#define CMILISECONDTIMER_H
//Begin section for file CMilisecondTimer.h
//TODO: Add definitions that you want preserved
//End section for file CMilisecondTimer.h
#include "CWin32MilisecondTimer.h"
#include "CLinuxMilisecondTimer.h"
#include "CAppleMilisecondTimer.h"



namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32MilisecondTimer CMilisecondTimer ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxMilisecondTimer CMilisecondTimer ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleMilisecondTimer CMilisecondTimer ;
    #endif


}//end namespace atom


#endif

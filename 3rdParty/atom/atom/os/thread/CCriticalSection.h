#ifndef CCRITICALSECTION_H
#define CCRITICALSECTION_H
//Begin section for file CCriticalSection.h
//TODO: Add definitions that you want preserved
//End section for file CCriticalSection.h
#include "CWin32CriticalSection.h"
#include "CLinuxCriticalSection.h"
#include "CAppleCriticalSection.h"


namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32CriticalSection CCriticalSection ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxCriticalSection CCriticalSection ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleCriticalSection CCriticalSection ;
    #endif


}//end namespace atom


#endif

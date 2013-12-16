#ifndef CSYSTEMTIMER_H
#define CSYSTEMTIMER_H
//Begin section for file CSystemTimer.h
//TODO: Add definitions that you want preserved
//End section for file CSystemTimer.h
#include "CWin32SystemTimer.h"
#include "CLinuxSystemTimer.h"
#include "CAppleSystemTimer.h"


namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32SystemTimer CSystemTimer ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxSystemTimer CSystemTimer ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleSystemTimer CSystemTimer ;
    #endif


}//end namespace atom


#endif

#ifndef CTHREAD_H
#define CTHREAD_H
//Begin section for file CThread.h
//TODO: Add definitions that you want preserved
//End section for file CThread.h
#include "CWin32Thread.h"
#include "CLinuxThread.h"
#include "CAppleThread.h"


namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32Thread CThread ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxThread CThread ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleThread CThread ;
    #endif


}//end namespace atom


#endif

#ifndef CSIGNAL_H
#define CSIGNAL_H
//Begin section for file CSignal.h
//TODO: Add definitions that you want preserved
//End section for file CSignal.h
#include "CWin32Signal.h"
#include "CLinuxSignal.h"
#include "CAppleSignal.h"


namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32Signal CSignal ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxSignal CSignal ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleSignal CSignal ;
    #endif


}//end namespace atom


#endif

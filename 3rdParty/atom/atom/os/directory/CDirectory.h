#ifndef CDIRECTORY_H
#define CDIRECTORY_H
//Begin section for file CDirectory.h
//TODO: Add definitions that you want preserved
//End section for file CDirectory.h
#include "CLinuxDirectory.h"
#include "CWin32Directory.h"
#include "CAppleDirectory.h"


namespace atom
{



    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32Directory  CDirectory ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxDirectory  CDirectory ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleDirectory  CDirectory ;
    #endif
	

} //end namespace atom

#endif

#ifndef CLIBRARY_H
#define CLIBRARY_H
//Begin section for file CLibrary.h
//TODO: Add definitions that you want preserved
//End section for file CLibrary.h
#include "CLinuxLibrary.h"
#include "CWin32Library.h"
#include "CAppleLibrary.h"


namespace atom
{



    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32Library CLibrary ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxLibrary CLibrary ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleLibrary CLibrary ;
    #endif
	

}//end namespace atom


#endif

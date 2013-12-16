#ifndef CCHARACTER_H
#define CCHARACTER_H
//Begin section for file CCharacter.h
//TODO: Add definitions that you want preserved
//End section for file CCharacter.h
#include "CWin32Character.h"
#include "CLinuxCharacter.h"
#include "CAppleCharacter.h"


namespace atom
{


    #ifdef _WIN32
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CWin32Character CCharacter ;
    #endif

    #ifdef __linux
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CLinuxCharacter CCharacter ;
    #endif

    #ifdef __APPLE__
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef CAppleCharacter CCharacter ;
    #endif


}//end namespace atom


#endif

#ifndef CCHARACTER_H
#define CCHARACTER_H
#include "CWin32Character.h"
#include "CLinuxCharacter.h"
#include "CAppleCharacter.h"


namespace atom
{


    #ifdef _WIN32
    typedef CWin32Character CCharacter ;
    #endif

    #ifdef __linux
    typedef CLinuxCharacter CCharacter ;
    #endif

    #ifdef __APPLE__
    typedef CAppleCharacter CCharacter ;
    #endif


}//end namespace atom


#endif

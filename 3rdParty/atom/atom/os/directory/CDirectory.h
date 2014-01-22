#ifndef CDIRECTORY_H
#define CDIRECTORY_H
#include "CLinuxDirectory.h"
#include "CWin32Directory.h"
#include "CAppleDirectory.h"


namespace atom
{



    #ifdef _WIN32
    typedef CWin32Directory  CDirectory ;
    #endif

    #ifdef __linux
    typedef CLinuxDirectory  CDirectory ;
    #endif

    #ifdef __APPLE__
    typedef CAppleDirectory  CDirectory ;
    #endif
	

} //end namespace atom

#endif

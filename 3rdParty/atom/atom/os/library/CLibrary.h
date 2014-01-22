#ifndef CLIBRARY_H
#define CLIBRARY_H
#include "CLinuxLibrary.h"
#include "CWin32Library.h"
#include "CAppleLibrary.h"


namespace atom
{



    #ifdef _WIN32
    typedef CWin32Library CLibrary ;
    #endif

    #ifdef __linux
    typedef CLinuxLibrary CLibrary ;
    #endif

    #ifdef __APPLE__
    typedef CAppleLibrary CLibrary ;
    #endif
	

}//end namespace atom


#endif

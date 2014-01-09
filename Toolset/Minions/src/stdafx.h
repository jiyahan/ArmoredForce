#pragma once

#ifdef _WIN32
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#   include <WinSDKVer.h>
#   include <SDKDDKVer.h>
#endif

#ifdef _MSC_VER
#   if _MSC_VER < 1700
#   error "项目代码使用了部分C++11特性，需要编译器为Visual C++ 2012或更高的版本."
#   endif
#endif

#include <cstdint>

#include <atom/CAtom.h>
#include <electron/CElectron.h>

#define _ELPP_THREAD_SAFE
#define _ELPP_STL_LOGGING
#define _ELPP_LOG_STD_ARRAY
#define _ELPP_LOG_UNORDERED_MAP
#define _ELPP_LOG_UNORDERED_SET
#include <easylogging++.h>


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
#   error "��Ŀ����ʹ���˲���C++11���ԣ���Ҫ������ΪVisual C++ 2012����ߵİ汾."
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


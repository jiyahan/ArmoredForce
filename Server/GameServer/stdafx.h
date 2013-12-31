#pragma once

#ifdef _WIN32
#   ifndef _WIN32_WINNT
#       define _WIN32_WINNT	    _WIN32_WINNT_WS08 	// Windows 2008
#   endif
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#endif

#ifdef _MSC_VER
#   if _MSC_VER < 1700
#   error "项目代码使用了部分C++11特性，需要编译器为Visual C++ 2012或更高的版本."
#   endif
#endif

#include <cstdint>
#include <glog/logging.h>

//#define RCF_USE_ZLIB
//#define RCF_USE_OPENSSL
//#define RCF_USE_PROTOBUF
#include <RCF/RCF.hpp>

#include <atom/CAtom.h>
#include <electron/CElectron.h>

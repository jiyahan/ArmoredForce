#pragma once

#ifdef _WIN32
#   ifndef _WIN32_WINNT
#       define _WIN32_WINNT	    0x0500	// Windows XP
#   endif
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#endif

#ifdef _MSC_VER
#   if _MSC_VER < 1700
#   error "��Ŀ����ʹ���˲���C++11���ԣ���Ҫ������ΪVisual C++ 2012����ߵİ汾."
#   endif
#endif

#include <cstdint>
#include <glog/logging.h>

#include <atom/CAtom.h>
#include <electron/CElectron.h>


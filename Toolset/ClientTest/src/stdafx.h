#pragma once


#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#ifdef _MSC_VER
#if _MSC_VER < 1800
#error "代码使用了C++11(variadic template, rvalue reference)，需要Visual C++ 2013或更高版本."
#endif
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


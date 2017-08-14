#pragma once

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#ifdef _MSC_VER
#if _MSC_VER < 1800
#error "����ʹ����C++11(variadic template, rvalue reference)����ҪVisual C++ 2013����߰汾."
#endif
#endif


#include <cstdint>

////#define RCF_USE_ZLIB
////#define RCF_USE_OPENSSL
////#define RCF_USE_PROTOBUF
#include <RCF/RCF.hpp>

#define _ELPP_THREAD_SAFE
#define _ELPP_STL_LOGGING
#define _ELPP_LOG_STD_ARRAY
#define _ELPP_LOG_UNORDERED_MAP
#define _ELPP_LOG_UNORDERED_SET
#include <easylogging++.h>

//#include <mysql++.h>
//
#include <atom/CAtom.h>
#include <electron/CElectron.h>

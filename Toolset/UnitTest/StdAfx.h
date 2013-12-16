#pragma once

#ifdef _WIN32
#   ifndef _WIN32_WINNT
#       define _WIN32_WINNT	    0x0502	// Windows 2003
#   endif
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#endif

#ifdef _MSC_VER
#   if _MSC_VER < 1600
#   error "You need Visual C++ 2010(or higher version) to compile this project."
#   endif
#endif

#ifndef GLOG_NO_ABBREVIATED_SEVERITIES
#define GLOG_NO_ABBREVIATED_SEVERITIES
#endif
#include <glog/logging.h>

#include <gtest/gtest.h>

#include <atom/CAtom.h>
#include <electron/CElectron.h>

using namespace atom;
using namespace electron;

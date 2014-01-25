//
// Precompiled header file
//

#pragma once

#include <cstdint>

#define BOOST_REGEX_NO_LIB
#define BOOST_ASIO_SEPARATE_COMPILATION
#define BOOST_ASIO_NO_DEFAULT_LINKED_LIBS
#include <boost/asio.hpp>

#define _ELPP_STL_LOGGING
#include "easylogging++.h"

#include <electron/message/CMessage.h>

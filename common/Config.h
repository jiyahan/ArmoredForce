#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <string>

#if defined(_MSC_VER) && _MSC_VER >= 1700
#include <unordered_map>
#endif

#ifndef __SERVER__
#   if defined (__ANDROID__) || defined(__WINDOWS__) || defined(__APPLE__)
#   include "cocos2d.h"
using namespace cocos2d;
#   endif
#endif


#ifdef NOT_USE_ATOM_ALLOCATOR
#define a_string        std::string
#endif


enum 
{
    GRID_AMOUNT = 6,        // 格子数
    MAX_ROUND = 32,         // 最大回合数
    MAX_REGION_STAGE = 3,   // 最大阶段
};

#endif // COMMON_CONFIG_H

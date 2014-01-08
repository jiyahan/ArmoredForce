#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <string>
#include <memory>


//
// 是否使用atom_allocator

#ifdef NOT_USE_ATOM_ALLOCATOR
#define atom_allocator  std::allocator
#define a_string        std::string
#endif



enum 
{
    GRID_AMOUNT = 6,        // 格子数
    MAX_ROUND = 32,         // 最大回合数
    MAX_REGION_STAGE = 3,   // 最大阶段
};

#endif // COMMON_CONFIG_H

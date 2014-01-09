/**
 * @file    Utility.h
 * @date    Dec 23, 2013
 * @author  
 * @brief   
 *
 */
#pragma once

#include <cstdio>
#include <string>
#include <boost/noncopyable.hpp>


// 自动初始化atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int pool_size, int thread_num);

    ~AtomAutoInit();
};

// 生成一个UUID
std::string     CreateUniqueID();


#ifndef NOT_USE_ATOM_ALLOCATOR
#define AS2Std(s)  as2std((s).c_str())
#else
#define AS2Std(s)   (s)
#endif
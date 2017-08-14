/**
 * @file    Utility.h
 * @date    Dec 23, 2013
 * @author  
 * @brief   
 *
 */
#pragma once

#include <cstdio>
#include <boost/noncopyable.hpp>


// 自动初始化atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int pool_size, int thread_num);

    ~AtomAutoInit();
};


// 随机数
uint32_t random(uint32_t max);

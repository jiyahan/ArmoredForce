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


// �Զ���ʼ��atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int pool_size, int thread_num);

    ~AtomAutoInit();
};


std::string     GetUniqueID();

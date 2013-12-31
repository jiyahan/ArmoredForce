/**
 * @file    Random.h
 * @date    Dec 23, 2013
 * @author  
 * @brief   A simple random number generator based on std::mt19937
 *
 */

#pragma once

#include <random>
#include <cstdint>

//
// 随机数生成器:
//      std::linear_congruential_engine，线性同余法
//      std::mersenne_twister_engine，梅森旋转法
//      std::substract_with_carry_engine，滞后Fibonacci
// 
//分布类型
//      std::uniform_int_distribution， 整数均匀分布
//      std::uniform_real_distribution，浮点数均匀分布
// 

// 每个线程使用一个Random对象产生随机数
class Random 
{
public:
    explicit Random(uint32_t seed = std::random_device()()) 
        : generator_(seed) 
    { }
    
    // Generates the next random number
    uint32_t Next() 
    { 
        return generator_(); 
    }

    // Returns a uniformly distributed value in the range [0..n-1]
    // REQUIRES: n > 0
    uint32_t Uniform(uint32_t n) 
    {
        return std::uniform_int_distribution<uint32_t>(0, n - 1)(generator_);
    }
private:
    std::default_random_engine       generator_;
};

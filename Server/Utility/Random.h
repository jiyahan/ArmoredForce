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
// �����������:
//      std::linear_congruential_engine������ͬ�෨
//      std::mersenne_twister_engine��÷ɭ��ת��
//      std::substract_with_carry_engine���ͺ�Fibonacci
// 
//�ֲ�����
//      std::uniform_int_distribution�� �������ȷֲ�
//      std::uniform_real_distribution�����������ȷֲ�
// 

// ÿ���߳�ʹ��һ��Random������������
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

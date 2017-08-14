/**
 * @file    Random.h
 * @author  chenqiang01@7aurora.com
 * @date    Dec 23, 2013
 * @brief   ����std::mt19937�������������
 *          ժ��: https://github.com/facebook/rocksdb/blob/master/util/random.h
 *
 *          �����������:
 *              std::linear_congruential_engine    ����ͬ�෨
 *              std::mersenne_twister_engine       ÷ɭ��ת��
 *              std::substract_with_carry_engine   �ͺ�Fibonacci
 *
 *          �ֲ�����
 *              std::uniform_int_distribution       �������ȷֲ�
 *              std::uniform_real_distribution      ���������ȷֲ� 
 */

#pragma once

#include <random>
#include <cstdint>

// ÿ���߳�ʹ��һ��Random������������
class Random 
{
public:
    explicit Random() 
        : generator_(std::random_device()()) 
    { }
    
    // Generates the next random number
    uint32_t Next() 
    { 
        return generator_(); 
    }
    
    // Randomly returns true ~"1/n" of the time, and false otherwise.
    // REQUIRES: n > 0
    bool OneIn(uint32_t n) { return Uniform(n) == 0; }

    // Returns a uniformly distributed value in the range [0..n-1]
    // REQUIRES: n > 0
    uint32_t Uniform(uint32_t n) 
    {
        return std::uniform_int_distribution<uint32_t>(0, n - 1)(generator_);
    }
private:
    std::default_random_engine       generator_;
};

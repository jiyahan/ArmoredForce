#pragma once

#include <array>
#include <boost/noncopyable.hpp>
#include "Officer.h"


// 一个部队的最大人数，6个格子
enum 
{
    TARGET_NONE = 0,    
    TARGET_POS1 = 1,
    POS_2 = 2,
    POS_3 = 3,
    POS_4 = 4,
    POS_5 = 5,
    POS_6 = 6,
    POS_RANDOM = 7,    
};

typedef std::array<OfficerPtr, MAX_OFFICER>     OfficerMatrix;


// 部队
class Troop : private boost::noncopyable
{
public:
    Troop();
    ~Troop();

private:
    OfficerMatrix       matrix_;   // 阵型 
};

typedef std::shared_ptr<Troop>    TroopPtr;

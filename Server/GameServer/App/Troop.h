#pragma once

#include <array>
#include <functional>
#include "Officer.h"


// 一个部队的最大人数，6个格子
enum {MAX_GRID = 6};

typedef std::array<OfficerPtr, MAX_GRID>     OfficerMatrix;
typedef std::function<void>     Delegate;


// 部队
class Troop
{
public:
    Troop();
    ~Troop();

    void    Attack();

private:
    OfficerMatrix       matrix_;   // 阵型 
};

typedef std::shared_ptr<Troop>    TroopPtr;

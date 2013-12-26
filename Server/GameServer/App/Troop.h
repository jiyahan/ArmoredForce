#pragma once

#include <array>
#include <functional>
#include "Officer.h"


typedef std::array<OfficerPtr, GRID_AMOUNT>     OfficerMatrix;
typedef std::function<void>     Delegate;


// 部队
class Troop
{
public:
    Troop();
    ~Troop();

    // 获取某一位置的军官
    OfficerPtr  GetOfficer(int32_t pos);

private:
    OfficerMatrix       matrix_;   // 阵型 
};

typedef std::shared_ptr<Troop>    TroopPtr;

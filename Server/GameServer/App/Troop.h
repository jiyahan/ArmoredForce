#pragma once

#include <array>
#include <functional>
#include "Officer.h"


// 部队
class Troop
{
public:
    // 阵型
    typedef std::array<Officer, GRID_AMOUNT>     Formation; 

public:
    Troop();
    ~Troop();

    // 获取某一位置的军官
    Officer*    GetOfficer(U16 pos);
    
    // 从部队里取一个攻击单位
    U16         GetNextAttacker();

    // 从部队里取一个防守单位
    U16         GetNextDefender(U16 attacker_pos);

private:
    Formation       formation_;         // 阵型 
    U16             last_attacker_;     // 上次攻击的位置
    U16             last_defender_;     // 上次防御的位置
};

typedef std::shared_ptr<Troop>    TroopPtr;

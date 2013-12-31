#pragma once

#include <array>
#include <tuple>
#include "Officer.h"

// 部队类型
enum eTroopType
{
    TROOP_NONE = 0,
    TROOP_ATTACKER = 1,     // 攻击方，左下角
    TROOP_DEFENDER = 2,     // 防守方，右下角
};


// 部队
class Troop
{
public:
    // 阵型
    typedef std::array<Officer, GRID_AMOUNT>     Formation; 

public:
    Troop();
    ~Troop();

    void        SetType(eTroopType type) {type_ = type;}
    eTroopType  GetType() const {return type_;}

    // 获取某一位置的军官，位置范围[1-6]
    Officer*    GetOfficer(I16 pos);
    
    // 从部队里取一个攻击单位
    I16         GetNextAttacker();

    // 从部队里取一个防守单位
    I16         GetNextDefender(I16 attacker_pos);

private:
    eTroopType      type_;
    Formation       formation_;         // 阵型 
    I16             last_attacker_;     // 上次攻击的位置
    I16             last_defender_;     // 上次防御的位置
};

typedef std::shared_ptr<Troop>    TroopPtr;

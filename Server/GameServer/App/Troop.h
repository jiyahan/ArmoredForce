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

class Troop;
typedef std::shared_ptr<Troop>    TroopPtr;

// 部队
class Troop
{
public:
    // 阵型
    typedef std::array<OfficerPtr, GRID_AMOUNT>     Formation; 

public:
    explicit Troop(const Formation& formation);
    ~Troop();

    void        SetType(eTroopType type) {type_ = type;}
    eTroopType  GetType() const {return type_;}

    // 获取某一位置的军官，位置范围[1-6]
    OfficerPtr  GetOfficer(U08 pos);
    
    // 从部队里取一个攻击单位
    U08         GetNextAttacker();

    // 从部队里取一个防守单位
    U08         GetNextDefender(U08 attacker_pos);

    // 从地图中生成一只队伍
    static TroopPtr  CreateFromRegion(const std::string& region_name, U32 stage);

private:
    eTroopType      type_;
    Formation       formation_;         // 阵型 
    U08             last_attacker_;     // 上次攻击的位置
    U08             last_defender_;     // 上次防御的位置
};

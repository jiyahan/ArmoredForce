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

    void        SetOwnerName(const std::string& name) {owner_name_ = name;}
    const std::string& GetOwnerName() const {return owner_name_;}

    // 获取所有军官的HP
    int32_t     GetTotalHp() const;

    // 获取某一位置的军官，位置范围[1-6]
    OfficerPtr  GetOfficer(uint8_t pos);
    
    // 从部队里取一个攻击单位
    uint8_t     GetNextAttacker();

    // 从部队里取一个防守单位
    uint8_t     GetNextDefender(uint8_t attacker_pos);

    // 从地图中生成一只队伍
    static TroopPtr  CreateFromRegion(const std::string& region_name, uint32_t stage);

private:
    eTroopType      type_;                  // 队伍类型
    std::string     owner_name_;            // 所属角色名称
    Formation       formation_;             // 阵型 
    uint8_t         last_attacker_pos_;     // 上次攻击的位置
    uint8_t         last_defender_pos_;     // 上次防御的位置
};

#pragma once

#include <queue>
#include <boost/noncopyable.hpp>
#include "Troop.h"

// 攻击目标
enum eTarget
{
    TARGET_NONE = 0,    // 没有目标   
    TARGET_POS1 = 1,    // 1号位
    TARGET_POS2 = 2,    // 2号位
    TARGET_POS3 = 3,    // 3号位
    TARGET_POS4 = 4,    // 4号位
    TARGET_POS5 = 5,    // 5号位
    TARGET_POS6 = 6,    // 6号位
    TARGET_RANDOM = 7,  // 随机目标
};


// 战斗
class BattleSys : private boost::noncopyable
{
public:
    BattleSys();
    ~BattleSys();

    void Fight(TroopPtr attacker, TroopPtr defender);


private:

};

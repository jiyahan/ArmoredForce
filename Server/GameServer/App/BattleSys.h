#pragma once

#include <queue>
#include <boost/noncopyable.hpp>
#include "Troop.h"


// 战斗
class BattleSys : private boost::noncopyable
{
public:
    BattleSys();
    ~BattleSys();

    void Fight(TroopPtr attacker, TroopPtr defender);


private:

};

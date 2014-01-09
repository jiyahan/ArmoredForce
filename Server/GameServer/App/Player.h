
#pragma once

#include <unordered_map>
#include <boost/noncopyable.hpp>
#include "common/RoleCommon.h"
#include "Officer.h"


// 角色
class Player : private boost::noncopyable
{
public:
    Player();
    ~Player();

    const a_string& GetName() {return property_.name;}
    int32_t     GetID() const {return property_.id;}
    int16_t     GetLevel() const {return property_.level;}
    int16_t     GetTitle() const {return property_.title;}
    int32_t     GetExp() const {return property_.exp;}
    int32_t     GetActionPoint() const {return property_.action_point;}
    int32_t     GetGoldCoin() const {return property_.gold;}
    int32_t     GetGemsNum() const {return property_.gems;}

private:
    RoleCommon                  property_;      // 基础属性 
    //std::unordered_set<Officer>
};

typedef std::shared_ptr<Player>    PlayerPtr;


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
    I32     GetID() const {return property_.id;}
    I16     GetLevel() const {return property_.level;}
    I16     GetTitle() const {return property_.title;}
    I32     GetExp() const {return property_.exp;}
    I32     GetActionPoint() const {return property_.action_point;}
    I32     GetGoldCoin() const {return property_.gold;}
    I32     GetGemsNum() const {return property_.gems;}

private:
    RoleCommon                  property_;      // 基础属性 
    //std::unordered_set<Officer>
};

typedef std::shared_ptr<Player>    PlayerPtr;

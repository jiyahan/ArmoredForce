
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

private:
    RoleCommon                  property_;      // 基础属性 
    //std::unordered_set<Officer>
};

typedef std::shared_ptr<Player>    PlayerPtr;

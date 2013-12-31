#include "Troop.h"


Troop::Troop()
{
    type_ = TROOP_NONE;
    last_attacker_ = 0;
    last_defender_ = 0;
}

Troop::~Troop()
{

}

Officer*  Troop::GetOfficer(I16 pos)
{
    CHECK(pos > 0 && pos <= formation_.max_size()) << "invalid position: " << pos;
    return std::addressof(formation_.at(pos-1));
}


// 下一个攻击者
I16  Troop::GetNextAttacker()
{
    for (size_t i = last_attacker_; i < formation_.size(); ++i)
    {
        if (!formation_[i].IsDead())
        {
            last_attacker_ = i+1;
            return last_attacker_;
        }
    }
    for (size_t i = 0; i < last_attacker_ && i < formation_.size(); ++i)
    {
        if (!formation_[i].IsDead())
        {
            last_attacker_ = i+1;
            return last_attacker_;
        }
    }
    return 0;
}

// 下一个防守者
I16 Troop::GetNextDefender(I16 attacker_pos)
{
    for (size_t i = last_defender_; i < formation_.size(); ++i)
    {
        if (!formation_[i].IsDead())
        {
            last_defender_ = i+1;
            return last_defender_;
        }
    }
    for (size_t i = 0; i < last_defender_ && i < formation_.size(); ++i)
    {
        if (!formation_[i].IsDead())
        {
            last_defender_ = i+1;
            return last_defender_;
        }
    }
    return 0;
}

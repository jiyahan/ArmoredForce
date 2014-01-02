#include "Troop.h"
#include "common/setup/RegionList.h"



Troop::Troop(const Formation& formation)
    : formation_(formation)
{
    type_ = TROOP_NONE;
    last_attacker_ = 0;
    last_defender_ = 0;
}

Troop::~Troop()
{
}

OfficerPtr  Troop::GetOfficer(U08 pos)
{
    CHECK(pos > 0U && pos <= formation_.max_size()) << "invalid position: " << pos;
    return formation_.at(pos-1);
}


// 下一个攻击者
U08  Troop::GetNextAttacker()
{
    for (auto i = last_attacker_; i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_attacker_ = i+1;
            return last_attacker_;
        }
    }
    for (auto i = 0U; i < last_attacker_ && i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_attacker_ = i+1;
            return last_attacker_;
        }
    }
    return 0;
}

// 下一个防守者
U08 Troop::GetNextDefender(U08 attacker_pos)
{
    for (auto i = last_defender_; i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_defender_ = i+1;
            return last_defender_;
        }
    }
    for (auto i = 0U; i < last_defender_ && i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_defender_ = i+1;
            return last_defender_;
        }
    }
    return 0;
}

// 从地图中生成一只队伍
TroopPtr Troop::CreateFromRegion(const std::string& region_name, U32 stage)
{
    CHECK(stage > 0 && stage <= MAX_REGION_STAGE) << "错误的战斗阶段";
    auto region = setup::RegionListSetup::GetInstance()->GetRegion(region_name.c_str());
    if (!region)
    {
        return nullptr;
    }
    const auto& monsters = region->stages[stage].monsters;
    std::array<OfficerPtr, GRID_AMOUNT> formation;
    for (int i = 0; i < GRID_AMOUNT; ++i)
    {
        const auto& index = monsters[i];
        auto monster = setup::MonsterListSetup::GetInstance()->GetMonster(index);
        if (!monster)
        {
            LOG_IF(ERROR, !monster) << "monster of index: " << index << "not found.";
            return nullptr;
        }
        formation[i] = std::make_shared<Officer>(*monster);
        formation[i]->SetPosition(i+1);
    }
    return std::make_shared<Troop>(formation);
}

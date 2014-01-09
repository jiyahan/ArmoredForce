#include "Troop.h"
#include "common/setup/RegionList.h"
#include "common/setup/MonsterList.h"
#include "common/setup/OfficerList.h"


Troop::Troop(const Formation& formation)
    : formation_(formation)
{
    type_ = TROOP_NONE;
    last_attacker_pos_ = 0;
    last_defender_pos_ = 0;
}

Troop::~Troop()
{
}

OfficerPtr  Troop::GetOfficer(uint8_t pos)
{
    CHECK(pos > 0U && pos <= formation_.max_size()) << "invalid position: " << pos;
    return formation_.at(pos-1);
}

int32_t  Troop::GetTotalHp() const
{
    int32_t total_hp = 0;
    for (const auto& officer: formation_)
    {
        total_hp += officer->GetHp();
    }
    return total_hp;
}

// 下一个攻击者
uint8_t  Troop::GetNextAttacker()
{
    for (auto i = last_attacker_pos_; i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_attacker_pos_ = i+1;
            return last_attacker_pos_;
        }
    }
    for (auto i = 0U; i < last_attacker_pos_ && i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_attacker_pos_ = i+1;
            return last_attacker_pos_;
        }
    }
    return 0;
}

// 下一个防守者
uint8_t Troop::GetNextDefender(uint8_t attacker_pos)
{
    for (auto i = last_defender_pos_; i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_defender_pos_ = i+1;
            return last_defender_pos_;
        }
    }
    for (auto i = 0U; i < last_defender_pos_ && i < formation_.size(); ++i)
    {
        if (!formation_[i]->IsDead())
        {
            last_defender_pos_ = i+1;
            return last_defender_pos_;
        }
    }
    return 0;
}

// 从地图中生成一只队伍
TroopPtr Troop::CreateFromRegion(const std::string& region_name, uint32_t stage)
{
    CHECK(stage > 0 && stage <= MAX_REGION_STAGE) << "错误的战斗阶段";
    auto region = setup::RegionListSetup::GetInstance()->GetRegion(region_name.c_str());
    if (!region)
    {
        return nullptr;
    }
    const auto& monsters = region->stages[stage-1].monsters;
    std::array<OfficerPtr, GRID_AMOUNT> formation;
    for (int i = 0; i < GRID_AMOUNT; ++i)
    {
        const auto& index = monsters[i];
        auto monster = setup::MonsterListSetup::GetInstance()->GetMonster(index);
        if (!monster)
        {
            LOG(ERROR) << "monster of index: " << index << " not found.";
            return nullptr;
        }
        auto officer = std::make_shared<Officer>(*monster);
        officer->SetPosition(i+1);
        formation[i] = officer;
        LOG(TRACE) << "位置: " << i+1 << "   攻防: " 
            << officer->GetAttack() << "/" << officer->GetHp()
            << "\t" << officer->GetName() << endl;
    }
    LOG(TRACE) << endl;
    return std::make_shared<Troop>(formation);
}

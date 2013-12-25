#pragma once

#include "../../common/setup/ArmyCategory.h"
#include "../../common/setup/MonsterList.h"
#include "../../common/setup/OfficerList.h"
#include "../../common/setup/RegionList.h"


namespace setup {

// 读取兵种配置
ArmyCategoryList    LoadArmyCategoryList(const std::string& file);


// 读取所有军官配置
OfficerList         LoadOfficerList(const std::string& file);


// 读取所有场景配置
RegionList          LoadRegionList(const std::string& file);


// 读取所有的怪物配置
MonsterList         LoadMonsterList(const std::string& file);

} // namespace setup

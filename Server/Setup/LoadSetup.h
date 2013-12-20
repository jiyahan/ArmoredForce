#pragma once

#include "../../common/setup/tagArmyCategory.h"
#include "../../common/setup/tagOfficer.h"
#include "../../common/setup/tagRegion.h"
#include <string>

namespace setup {

// 读取兵种
ArmyCategoryMap     LoadArmyCategoryMap(const std::string& file);

// 读取所有军官
OfficerMap  LoadOffficerMap(const std::string& file);

// 读取所有场景
RegionMap   LoadRegionMap(const std::string& file);


} // namespace setup

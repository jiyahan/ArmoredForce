#pragma once

#include "../../common/setup/tagArmyCategory.h"
#include "../../common/setup/tagOfficer.h"
#include "../../common/setup/tagRegion.h"
#include <string>

namespace setup {

// ��ȡ����
ArmyCategoryMap     LoadArmyCategoryMap(const std::string& file);

// ��ȡ���о���
OfficerMap  LoadOffficerMap(const std::string& file);

// ��ȡ���г���
RegionMap   LoadRegionMap(const std::string& file);


} // namespace setup

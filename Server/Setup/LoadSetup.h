#pragma once

#include "../../common/setup/ArmyCategory.h"
#include "../../common/setup/MonsterList.h"
#include "../../common/setup/OfficerList.h"
#include "../../common/setup/RegionList.h"


namespace setup {

// ��ȡ��������
ArmyCategoryList    LoadArmyCategoryList(const std::string& file);


// ��ȡ���о�������
OfficerList         LoadOfficerList(const std::string& file);


// ��ȡ���г�������
RegionList          LoadRegionList(const std::string& file);


// ��ȡ���еĹ�������
MonsterList         LoadMonsterList(const std::string& file);

} // namespace setup

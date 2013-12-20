#include "LoadSetup.h"
#include "../Utility/Markup.h"


namespace setup {

// 读取兵种
ArmyCategoryMap LoadArmyCategoryMap(const std::string& file)
{
    ArmyCategoryMap result;
    CMarkup xml;
    if (!xml.Load(file))
    {
        return std::move(result);
    }
    if (!xml.FindElem("category"))
    {
        return std::move(result);
    }
    xml.IntoElem();
    while (xml.FindElem("army"))
    {
        tagArmyCategory category = {};
        category.name = xml.GetAttrib("name");
        category.type = (tagArmyCategory::ArmyType)std::stoi(xml.GetAttrib("type"));
        category.picture_id = xml.GetAttrib("picture_id");
        category.animation_id = xml.GetAttrib("animation_id");
        category.general_skill = xml.GetAttrib("general_skill");
        category.active_skill = xml.GetAttrib("active_skill");
        category.passive_skill = xml.GetAttrib("passive_skill");
        category.intro = xml.GetAttrib("intro");
        category.skill_desc = xml.GetAttrib("skill_desc");
        result[category.name] = category;
    }

    return std::move(result);
}

// 读取所有军官
OfficerMap  LoadOffficerMap(const std::string& file)
{
    OfficerMap result;
    CMarkup xml;
    if (!xml.Load(file))
    {
        return std::move(result);
    }
    if (!xml.FindElem("monster_list"))
    {
        return std::move(result);
    }
    while (xml.FindElem("monster"))
    {
        tagOfficer officer = {};
        officer.name = xml.GetAttrib("name");
        officer.index = xml.GetAttrib("index");
        officer.category = xml.GetAttrib("category");
        officer.quality = (tagOfficer::Quality)std::stoi(xml.GetAttrib("quality"));
        officer.base_hp = std::stoi(xml.GetAttrib("base_hp"));
        officer.command_force = std::stoi(xml.GetAttrib("commander_force"));        
        officer.leadership = std::stoi(xml.GetAttrib("leadership"));
        officer.base_atk = std::stoi(xml.GetAttrib("base_atk"));
        officer.atk_upgrade = std::stoi(xml.GetAttrib("atk_upgrade"));
        officer.base_force = std::stoi(xml.GetAttrib("base_force"));
        officer.force_upgrade = std::stoi(xml.GetAttrib("force_upgrade"));
        officer.price = std::stoi(xml.GetAttrib("price"));
        officer.picture_large = xml.GetAttrib("picture_large");
        officer.picture_small = xml.GetAttrib("picture_small");
        officer.intro = xml.GetAttrib("intro");
        result[officer.index] = officer;
    }
    return std::move(result);
}

// 读取所有场景
RegionMap   LoadRegionMap(const std::string& file)
{
    RegionMap result;
    CMarkup xml;
    if (!xml.Load(file))
    {
        return std::move(result);
    }
    if (!xml.FindElem("region_list"))
    {
        return std::move(result);
    }
    while (xml.FindElem("region"))
    {
        tagRegion region = {};
        region.name = xml.GetAttrib("name");
        region.index = xml.GetAttrib("index");
        xml.IntoElem();
        if (xml.FindElem("stage_1"))
        {

        }
        xml.OutOfElem();
    }
    return std::move(result);
}


} // namespace setup

#include "LoadSetup.h"
#include <glog/logging.h>
#include "../Utility/Markup.h"


namespace setup {

// 读取兵种
ArmyCategoryList LoadArmyCategoryList(const std::string& file)
{
    ArmyCategoryList result;
    CMarkup xml;
    CHECK(xml.Load(file)) << xml.GetError() << file;
    CHECK(xml.FindElem("category")) << "<category> not found.";
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
OfficerList  LoadOfficerList(const std::string& file)
{
    OfficerList result;
    CMarkup xml;
    CHECK(xml.Load(file)) << xml.GetError() << file;
    CHECK(xml.FindElem("officer_list")) << "<officer_list> not found.";
    xml.IntoElem();
    while (xml.FindElem("officer"))
    {
        tagOfficer officer = {};
        officer.name = xml.GetAttrib("name");
        officer.index = xml.GetAttrib("index");
        officer.category = xml.GetAttrib("category");
        officer.quality = (tagOfficer::Quality)std::stoi(xml.GetAttrib("quality"));
        officer.command_force = std::stoi(xml.GetAttrib("commander_force"));        
        officer.leadership = std::stoi(xml.GetAttrib("leadership"));
        officer.base_atk = std::stoi(xml.GetAttrib("base_attack"));
        officer.atk_upgrade = std::stoi(xml.GetAttrib("attack_upgrade"));
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

tagRegionStage LoadStage(CMarkup& xml, const string& name)
{
    tagRegionStage stage = {};
    if (xml.FindElem(name))
    {
        xml.IntoElem();
        if (xml.FindElem("monsters"))
        {                
            stage.pos_1 = xml.GetAttrib("pos_1");
            stage.pos_2 = xml.GetAttrib("pos_2");
            stage.pos_3 = xml.GetAttrib("pos_3");
            stage.pos_4 = xml.GetAttrib("pos_4");
            stage.pos_5 = xml.GetAttrib("pos_5");
            stage.pos_6 = xml.GetAttrib("pos_6");                
        }
        while (xml.FindElem("prize"))
        {
            tagPrize prize = {};
            prize.name = xml.GetAttrib("name");
            prize.index = xml.GetAttrib("id");
            prize.count = std::stoi(xml.GetAttrib("num"));
            stage.prize.emplace_back(prize);
        }
        xml.OutOfElem();
    }
    return std::move(stage);
}

// 读取所有场景
RegionList   LoadRegionList(const std::string& file)
{
    RegionList regions;
    CMarkup xml;
    CHECK(xml.Load(file)) << xml.GetError() << file;
    CHECK(xml.FindElem("region_list")) << "<region_list> not found.";
    xml.IntoElem();
    while (xml.FindElem("region"))
    {
        tagRegion region = {};
        region.name = xml.GetAttrib("name");
        region.index = xml.GetAttrib("id");
        region.type = std::stoi(xml.GetAttrib("type"));
        xml.IntoElem();
        region.stages[0] = LoadStage(xml, "stage_1");
        region.stages[1] = LoadStage(xml, "stage_2");
        region.stages[2] = LoadStage(xml, "stage_3");
        regions[region.index] = region;
        xml.OutOfElem();
    }
    return std::move(regions);
}

// 读取所有的怪物配置
MonsterList   LoadMonsterList(const std::string& file)
{
    MonsterList monsters;
    CMarkup xml;
    CHECK(xml.Load(file)) << xml.GetError() << file;
    CHECK(xml.FindElem("monster_list")) << "<monster_list> not found.";
    xml.IntoElem();
    while (xml.FindElem("monster"))
    {
        tagMonster monster = {};
        monster.name = xml.GetAttrib("name");
        monster.index = xml.GetAttrib("index");
        monster.category = xml.GetAttrib("category");
        monster.type = std::stoi(xml.GetAttrib("type"));        
        monster.attack = std::stoi(xml.GetAttrib("attack"));
        monster.force = std::stoi(xml.GetAttrib("force"));
        monster.blast = std::stoi(xml.GetAttrib("blast"));
        monster.accuracy = std::stoi(xml.GetAttrib("accuracy"));
        xml.IntoElem();
        if (xml.FindElem("drop_things"))
        {
            xml.IntoElem();
            while (xml.FindElem("drop"))
            {
                tagDropThing thing = {};
                thing.index = xml.GetAttrib("index");
                thing.num = std::stoi(xml.GetAttrib("num"));
                thing.rate = std::stoi(xml.GetAttrib("rate"));
                monster.drop_things.emplace_back(thing);
            }
            xml.OutOfElem();
        }
        xml.OutOfElem();
        monsters[monster.index] = monster;
    }
    return std::move(monsters);
}

} // namespace setup

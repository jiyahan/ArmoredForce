#include "LoadSetup.h"
#include <glog/logging.h>
#include "../Utility/Markup.h"


namespace setup {

// ��ȡ����
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
        category.name = xml.GetAttrib("name").c_str();
        category.type = (tagArmyCategory::ArmyType)std::stoi(xml.GetAttrib("type"));
        category.picture_id = xml.GetAttrib("picture_id").c_str();
        category.animation_id = xml.GetAttrib("animation_id").c_str();
        category.general_skill = xml.GetAttrib("general_skill").c_str();
        category.active_skill = xml.GetAttrib("active_skill").c_str();
        category.passive_skill = xml.GetAttrib("passive_skill").c_str();
        category.intro = xml.GetAttrib("intro").c_str();
        category.skill_desc = xml.GetAttrib("skill_desc").c_str();
        result[category.name] = category;
    }

    return std::move(result);
}

// ��ȡ���о���
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
        officer.name = xml.GetAttrib("name").c_str();
        officer.index = xml.GetAttrib("index").c_str();
        officer.category = xml.GetAttrib("category").c_str();
        officer.quality = (tagOfficer::Quality)std::stoi(xml.GetAttrib("quality"));
        officer.command_force = std::stoi(xml.GetAttrib("commander_force"));        
        officer.leadership = std::stoi(xml.GetAttrib("leadership"));
        officer.base_atk = std::stoi(xml.GetAttrib("base_attack"));
        officer.atk_upgrade = std::stoi(xml.GetAttrib("attack_upgrade"));
        officer.base_force = std::stoi(xml.GetAttrib("base_force"));
        officer.force_upgrade = std::stoi(xml.GetAttrib("force_upgrade"));
        officer.price = std::stoi(xml.GetAttrib("price"));
        officer.picture_large = xml.GetAttrib("picture_large").c_str();
        officer.picture_small = xml.GetAttrib("picture_small").c_str();
        officer.intro = xml.GetAttrib("intro").c_str();
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
            stage.monsters[0] = xml.GetAttrib("pos_1").c_str();
            stage.monsters[1] = xml.GetAttrib("pos_2").c_str();
            stage.monsters[2] = xml.GetAttrib("pos_3").c_str();
            stage.monsters[3] = xml.GetAttrib("pos_4").c_str();
            stage.monsters[4] = xml.GetAttrib("pos_5").c_str();
            stage.monsters[5] = xml.GetAttrib("pos_6").c_str();                
        }
        while (xml.FindElem("prize"))
        {
            tagPrize prize = {};
            prize.name = xml.GetAttrib("name").c_str();
            prize.index = xml.GetAttrib("id").c_str();
            prize.count = std::stoi(xml.GetAttrib("num"));
            stage.prize.emplace_back(prize);
        }
        xml.OutOfElem();
    }
    return std::move(stage);
}

// ��ȡ���г���
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
        region.name = xml.GetAttrib("name").c_str();
        region.index = xml.GetAttrib("id").c_str();
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

// ��ȡ���еĹ�������
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
        monster.name = xml.GetAttrib("name").c_str();
        monster.index = xml.GetAttrib("index").c_str();
        monster.category = xml.GetAttrib("category").c_str();
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
                thing.index = xml.GetAttrib("index").c_str();
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

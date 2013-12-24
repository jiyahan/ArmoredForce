#pragma once

#include <string>

enum CommandType 
{
    CmdError,           // 错误
    CmdMonsterList,     // 转换怪物列表
    CmdOfficerList,     // 军官列表
    CmdArmyCategory,    // 兵种列表 
    CmdRegionList,      // 转换地图列表
    CmdWeaponList,      // 转换军备列表
    CmdGlobalSetup,     // 转换全局配置
};


// 执行转换
void RunTransform(CommandType cmd, 
                  const std::string& file, 
                  const std::string& outfile);


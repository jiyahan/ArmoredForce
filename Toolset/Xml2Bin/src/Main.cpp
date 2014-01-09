#include "command.h"
#include <string>
#include <tuple>
#include <iostream>
#include <easylogging++.h>
#include <boost/program_options.hpp>
#include "Utility.h"

using namespace std;
using namespace atom;


_INITIALIZE_EASYLOGGINGPP


typedef std::tuple<CommandType, string, string> ParseResult;


// 解析命令
ParseResult ParseCommand(int argc, const char* argv[])
{
    using namespace boost::program_options;
    options_description desc("Xml2Bin，转换XML文件为二进制格式，valid options");
    desc.add_options()
        ("help,h", "查看使用说明")
        ("monsterlist,m", value<string>(), "转换怪物配置")
        ("officerlist,o", value<string>(), "转换军官配置")
        ("regionlist,r", value<string>(), "转换地图配置") 
        ("category,c", value<string>(), "转换兵种配置")
        ("weaponlist,w", value<string>(), "转换军备配置")
        ("globalsetup,g", value<string>(), "转换全局配置")        
        ;

    variables_map varmap;
    store(parse_command_line(argc, argv, desc), varmap);
    notify(varmap);

    CommandType cmd = CmdError;
    string filename;
    string output;

    if (varmap.count("help"))
    {
        cout << desc << endl;
    }
    else if (varmap.count("monsterlist")) // 怪物列表
    {
        cmd = CmdMonsterList;
        filename = varmap["monsterlist"].as<string>();
    }
    else if (varmap.count("officerlist")) // 军官列表
    {
        cmd = CmdOfficerList;
        filename = varmap["officerlist"].as<string>();
    }
    else if (varmap.count("regionlist")) // 地图列表
    {
        cmd = CmdRegionList;
        filename = varmap["regionlist"].as<string>();
    }
    else if (varmap.count("category"))  // 兵种列表
    {
        cmd = CmdArmyCategory;
        filename = varmap["category"].as<string>();
    }
    else if (varmap.count("weaponlist"))  // 军备列表
    {
        cmd = CmdArmyCategory;
        filename = varmap["weaponlist"].as<string>();
    }
    else if (varmap.count("globalsetup"))  // 全局配置
    {
        cmd = CmdArmyCategory;
        filename = varmap["globalsetup"].as<string>();
    }
    else if (varmap.count("output")) // 输出文件名称
    {
        output = varmap["output"].as<string>();
    }
    else
    {
        cout << desc << endl;
    }

    if (output.empty() && !filename.empty())
    {
        output = filename + ".bin";
    }

    return make_tuple(cmd, filename, output);
}


int main(int argc, const char* argv[])
{
    try
    {
        AtomAutoInit init(1024*32, 1);
        
        CommandType cmd;
        string filename;
        string output;
        std::tie(cmd, filename, output) = ParseCommand(argc, argv);
        if (cmd != CmdError)
        {
            RunTransform(cmd, filename, output);
        }
    }
    catch(std::exception& ex)
    {        
        cerr << typeid(ex).name() << ": " << ex.what() << endl;
    }

    return 0;
}
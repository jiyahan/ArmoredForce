#include "command.h"
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <atom/CAtom.h>
#include <glog/logging.h>
#include "Utility.h"

using namespace std;



void PrintUsage()
{
    const char* usage = "Usage: \n\tXml2Bin [--配置类型] [输入文件(xml)] [输出文件(bin)].\n"
        "\t配置类型\n"
        "\t\t--monsterlist\t怪物配置\n"
        "\t\t--officerlist\t军官配置\n"
        "\t\t--regionlist\t地图配置\n"
        "\t\t--category\t兵种配置\n"
        ;
    cout << usage << endl;
}

// 解析命令
tuple<CommandType, string, string> ParseCommand(int argc, const char* argv[])
{
    string filename;
    string output;
    CommandType cmdtype = CmdError;
    if (argc < 3)
    {
        return make_tuple(cmdtype, filename, output);
    }
   
    string cmd = argv[1];
    if (cmd == "--monsterlist")
    {
        cmdtype = CmdMonsterList;
    }
    else if (cmd == "--category")
    {
        cmdtype = CmdArmyCategory;
    }
    else if (cmd == "--regionlist")
    {
        cmdtype = CmdRegionList;
    }
    else if (cmd == "--officerlist")
    {
        cmdtype = CmdOfficerList;
    }

    filename = argv[2];
    if (argc > 3)
    {
        output = argv[3];        
    }
    else
    {
        output = filename + ".bin";
    }

    //for (int i = 2; i < argc; ++i)
    //{
    //    string cmd = argv[i];
    //    size_t pos = cmd.find_first_of('=');
    //    if (pos == string::npos)
    //    {
    //        filename = cmd;
    //        break;
    //    }
    //    string key = cmd.substr(0, pos);
    //    string value;
    //    if (++pos < cmd.length())
    //    {
    //         value = cmd.substr(pos);
    //    }
    //}
    return make_tuple(cmdtype, filename, output);;
}


int main(int argc, const char* argv[])
{
    using namespace atom;
    try
    {
        google::InitGoogleLogging(argv[0]);
        AtomAutoInit init(1024*32, 1);
        
        CommandType cmd;
        string filename;
        string output;
        std::tie(cmd, filename, output) = ParseCommand(argc, argv);
        if (cmd == CmdError)
        {
            PrintUsage();
        }
        else
        {
            RunTransform(cmd, filename, output);
        }
    }
    catch(std::exception& ex)
    {        
        cerr << typeid(ex).name() << ": " << ex.what() << endl;
    }

    google::ShutdownGoogleLogging();
    return 0;
}
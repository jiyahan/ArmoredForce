#include "command.h"
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <atom/CAtom.h>
#include "Utility.h"

using namespace std;



void PrintUsage()
{
    const char* usage = "Usage: \n\tXml2Bin [--��������] [�����ļ�(xml)] [����ļ�(bin)].\n"
        "\t��������\n"
        "\t\t--monsterlist\t��������\n"
        "\t\t--officerlist\t��������\n"
        "\t\t--regionlist\t��ͼ����\n"
        "\t\t--category\t��������\n"
        ;
    cout << usage << endl;
}

// ��������
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

    return 0;
}
#include "command.h"
#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <atom/CAtom.h>


using namespace std;



void PrintUsage()
{
    const char* usage = "Usage: \n\tXml2Bin --[cmd] [option=value] [file]."
        "\t\t--monsterlist output=[output]\n"
        "\t\t--regionlist output=[output]\n"
        ;
    cout << usage << endl;
}

// ½âÎöÃüÁî
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
        cmdtype = CmdMonster;
    }
    else if (cmd == "--category")
    {
        cmdtype = CmdArmyCategory;
    }
    else if (cmd == "--regionlist")
    {
        cmdtype = CmdRegionList;
    }

    for (int i = 2; i < argc; ++i)
    {
        string cmd = argv[i];
        size_t pos = cmd.find_first_of('=');
        if (pos == string::npos)
        {
            filename = cmd;
            break;
        }
        string key = cmd.substr(0, pos);
        string value;
        if (++pos < cmd.length())
        {
             value = cmd.substr(pos);
        }
        if (key == "out")
        {
            output = value;
        }
        
    }
    return make_tuple(cmdtype, filename, output);;
}


int main(int argc, const char* argv[])
{
    using namespace atom;
    try
    {
        CAtom::Presetup();
        CAtom::Initiate(1024 * 32);
        
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
    catch(...)
    {
        cerr << "unexpected exception.\n";
    }

    CAtom::Destruct();
    CAtom::Shutdown();

    return 0;
}
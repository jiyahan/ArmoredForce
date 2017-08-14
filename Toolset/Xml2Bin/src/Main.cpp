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


// ��������
ParseResult ParseCommand(int argc, const char* argv[])
{
    using namespace boost::program_options;
    options_description desc("Xml2Bin��ת��XML�ļ�Ϊ�����Ƹ�ʽ��valid options");
    desc.add_options()
        ("help,h", "�鿴ʹ��˵��")
        ("monsterlist,m", value<string>(), "ת����������")
        ("officerlist,o", value<string>(), "ת����������")
        ("regionlist,r", value<string>(), "ת����ͼ����") 
        ("category,c", value<string>(), "ת����������")
        ("weaponlist,w", value<string>(), "ת����������")
        ("globalsetup,g", value<string>(), "ת��ȫ������")        
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
    else if (varmap.count("monsterlist")) // �����б�
    {
        cmd = CmdMonsterList;
        filename = varmap["monsterlist"].as<string>();
    }
    else if (varmap.count("officerlist")) // �����б�
    {
        cmd = CmdOfficerList;
        filename = varmap["officerlist"].as<string>();
    }
    else if (varmap.count("regionlist")) // ��ͼ�б�
    {
        cmd = CmdRegionList;
        filename = varmap["regionlist"].as<string>();
    }
    else if (varmap.count("category"))  // �����б�
    {
        cmd = CmdArmyCategory;
        filename = varmap["category"].as<string>();
    }
    else if (varmap.count("weaponlist"))  // �����б�
    {
        cmd = CmdArmyCategory;
        filename = varmap["weaponlist"].as<string>();
    }
    else if (varmap.count("globalsetup"))  // ȫ������
    {
        cmd = CmdArmyCategory;
        filename = varmap["globalsetup"].as<string>();
    }
    else if (varmap.count("output")) // ����ļ�����
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
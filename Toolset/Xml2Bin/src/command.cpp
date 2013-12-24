#include "command.h"
#include <iostream>
#include <atom/CAtom.h>
#include "../../Server/Setup/LoadSetup.h"
#include "../../common/setup/LoadBinaryFile.h"

using namespace std;
using namespace atom;
using namespace setup;



template <typename T>
bool WriteMemoryToFile(const T& value, const string& path)
{
    CMemory data;
    CArchive ar;
    int version = 1;
    ar << version << value;
    ar.Clone(data);

    CFile file(path.c_str());
    if (file.Open())
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) 
        {
            segment->Write(data, data.GetLength());
            return true;
        }
    }
    return false;
}


template <typename T, typename Fn>
void DoTransform(Fn loader, T*, const string& infile, const string& outfile)
{
    auto v = loader(infile);
    WriteMemoryToFile(v, outfile);
    auto v2 = setup::LoadBinaryFile<T>(outfile);
    assert(!v.empty() && v.size() == v2.size());
}

void RunTransform(CommandType cmd, const std::string& infile, const std::string& outfile)
{    
    switch (cmd)         
    {
    case CmdArmyCategory:
        DoTransform(LoadArmyCategoryList, (ArmyCategoryList*)nullptr, infile, outfile);
        break;

    case CmdRegionList:
        DoTransform(LoadRegionList, (RegionList*)nullptr, infile, outfile);
        break;

    case CmdMonsterList:
        DoTransform(LoadMonsterList, (MonsterList*)nullptr, infile, outfile);
        break;

    case CmdOfficerList:
        DoTransform(LoadOfficerList, (OfficerList*)nullptr, infile, outfile);
        break;
    }
    cout << "OK. " << infile << " ==> " << outfile << endl;
}

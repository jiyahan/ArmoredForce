#include "command.h"
#include <iostream>
#include <atom/CAtom.h>
#include "../../Server/Setup/LoadSetup.h"

using namespace std;
using namespace atom;
using namespace setup;


void TestLoadFile(const string& path)
{
    CMemory data = CFile::LoadFile(path.c_str());
    if (data.GetLength() > 0)
    {
        CArchive ar;
        ar.Assign(data);
        ArmyCategoryMap category;
        ar >> category;
        cout << category.size();
    }
}

template <typename T>
bool WriteMemoryToFile(const T& value, const string& path)
{
    CMemory data;
    CArchive ar;
    ar << value;
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



void RunTransform(CommandType cmd, 
                  const std::string& infile, 
                  const std::string& outfile)
{    
    CMemory data;
    if (cmd == CmdArmyCategory)
    {
        WriteMemoryToFile(LoadArmyCategoryMap(infile), outfile);
    }
    else if (cmd == CmdRegionList)
    {
        WriteMemoryToFile(LoadRegionMap(infile), outfile);
    }
    else if (cmd == CmdMonster)
    {
        WriteMemoryToFile(LoadOffficerMap(infile), outfile);
    }
}

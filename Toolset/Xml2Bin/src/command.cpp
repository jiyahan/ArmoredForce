#include "command.h"
#include <iostream>
#include <atom/CAtom.h>
#include "../../Server/Setup/LoadSetup.h"

using namespace std;
using namespace atom;
using namespace setup;

CMemory TransformMonsterList(const std::string& file)
{
    OfficerMap monsterlist = LoadOffficerMap(file);
    CArchive archive;
    archive << monsterlist.size();
    archive << 
    CMemory data;
}


void RunTransform(CommandType cmd, 
                   const std::string& file, 
                   const std::string& outfile)
{

}

void LoadFile()
{
    const char* path = "main.cpp";
    CMemory data = CFile::LoadFile(path);
    cout << data.GetLength();
}

void WriteFile()
{
    const char* name = "";
    CMemory data;
    CFile file( name );
    if( file.Open() )
    {
        CInterface<IFileStream> segment;
        if( segment.Mount(&file, IID_FILE_STREAM) ) 
        {
            segment->Write(&data, data.GetLength());
        }
    }

}
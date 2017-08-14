#pragma once

#include <string>

enum CommandType 
{
    CmdError,           // ����
    CmdMonster,         // ת�������б�
    CmdRegionList,      // ת����ͼ�б�
    CmdWeaponList,      // ת�������б�
    CmdGlobalSetup,     // ת��ȫ������
};


// ִ��ת��
void RunTransform(CommandType cmd, 
                  const std::string& file, 
                  const std::string& outfile);


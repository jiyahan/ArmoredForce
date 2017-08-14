#pragma once

#include <string>

enum CommandType 
{
    CmdError,           // ����
    CmdMonster,         // ת�������б�
    CmdArmyCategory,    // �����б� 
    CmdRegionList,      // ת����ͼ�б�
    CmdWeaponList,      // ת�������б�
    CmdGlobalSetup,     // ת��ȫ������
};


// ִ��ת��
void RunTransform(CommandType cmd, 
                  const std::string& file, 
                  const std::string& outfile);


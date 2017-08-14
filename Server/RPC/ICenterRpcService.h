#pragma once

#include <cstdint>
#include <string>
#include <RCF/RCF.hpp>
#include <SF/string.hpp>


//
// �ӿڶ���
//  CenterServerʵ�����½ӿ�
//  LoginServer, GameServerʹ����Щ�ӿ�
//


RCF_BEGIN(ICenterRpcService, "ICenterRpcService")

    // ��ȡGameServer��ַ
    RCF_METHOD_R2(bool, GetGameServerAddress, std::string&, int16_t&)
    
    // ��¼��֤��
    RCF_METHOD_R1(std::string, GetLoginSignature, const std::string&)

    // ע��GameServer
    RCF_METHOD_R2(bool, RegisterGameServer, const std::string&, int16_t)
    
RCF_END(ICenterRpcService)

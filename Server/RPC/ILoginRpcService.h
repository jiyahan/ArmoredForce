#pragma once

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
    RCF_METHOD_R0(RCF::TcpEndpoint, GetGameServerAddress)
    
    // 
    RCF_METHOD_R1(std::string, GetLoginSignature, const std::string&)

    // 
    RCF_METHOD_R2(bool, RegisterGameServer, const std::string&, int)
    
RCF_END(ICenterRpcService)

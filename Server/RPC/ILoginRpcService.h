#pragma once

#include <string>
#include <RCF/RCF.hpp>
#include <SF/string.hpp>


//
// 接口定义
//  CenterServer实现以下接口
//  LoginServer, GameServer使用这些接口
//


RCF_BEGIN(ICenterRpcService, "ICenterRpcService")

    // 获取GameServer地址
    RCF_METHOD_R0(RCF::TcpEndpoint, GetGameServerAddress)
    
    // 
    RCF_METHOD_R1(std::string, GetLoginSignature, const std::string&)

    // 
    RCF_METHOD_R2(bool, RegisterGameServer, const std::string&, int)
    
RCF_END(ICenterRpcService)

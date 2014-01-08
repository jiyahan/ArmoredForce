#pragma once

#include <cstdint>
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
    RCF_METHOD_R2(bool, GetGameServerAddress, std::string&, int16_t&)
    
    // 登录验证码
    RCF_METHOD_R1(std::string, GetLoginSignature, const std::string&)

    // 注册GameServer
    RCF_METHOD_R2(bool, RegisterGameServer, const std::string&, int16_t)
    
RCF_END(ICenterRpcService)

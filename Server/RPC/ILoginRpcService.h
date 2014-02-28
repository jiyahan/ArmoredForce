#pragma once

#include <string>
#include <RCF/RCF.hpp>
#include <SF/string.hpp>


//
// 接口定义
//  LoginServer
//  CenterServer使用这些接口
//


RCF_BEGIN(ILoginRpcService, "ILoginRpcService")
    // 
    RCF_METHOD_R1(std::string, GetUserLoginSign, const std::string&)
    
    RCF_METHOD_V1(void, DelUserLoginSign, const std::string&)

    RCF_METHOD_V4(void, PutGameAddress, const std::string&, const std::string&, 
                  const std::string&, int16_t)
    
RCF_END(ILoginRpcService)

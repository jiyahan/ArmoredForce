#pragma once

#include <RCF/RCF.hpp>

//
// RPC接口定义
//  DBServer实现以下接口
//  CenterServer使用这些接口
//

RCF_BEGIN(IDBRpcService, "IDBRpcService")    
    // 登录
    RCF_METHOD_R2(int, QueryLogin, const std::string&, const std::string&)      

    // 注册
    RCF_METHOD_R2(int, RegisterUser, const std::string&, const std::string&)
RCF_END(IDBRpcService)

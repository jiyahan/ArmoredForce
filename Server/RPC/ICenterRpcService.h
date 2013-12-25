#pragma once

#include <string>
#include <utility>
#include <RCF/RCF.hpp>
#include <SF/string.hpp>


//
// 接口定义
//  CenterServer实现以下接口
//  LoginServer, GameServer使用这些接口
//

typedef std::pair<std::string, int>  ServerAddress;

namespace SF {

inline void serialize(SF::Archive& ar, ServerAddress& addr)
{
    ar & addr.first & addr.second;
}

} // namespace SF


RCF_BEGIN(ICenterRpcService, "ICenterRpcService")

    // 获取GameServer地址
    RCF_METHOD_R0(ServerAddress, GetGameServerAddress)
    
    // 
    RCF_METHOD_R1(std::string, GetLoginSignature, const std::string&)

    // 
    RCF_METHOD_R2(bool, RegisterGameServer, const std::string&, int)
    
RCF_END(ICenterRpcService)

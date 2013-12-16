#pragma once

#include <unordered_map>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "CenterRpcService.h"
#include "../Utility/Singleton.h"


//
// 中心服务器
//
class CenterServer : public Singleton<CenterServer>
{
public:
    CenterServer();
    ~CenterServer();

    //初始化
    bool    Init();

    // 释放资源
    void    Release();

    // 运行服务器
    bool    Run();

    // 停止服务器
    void    Stop();

private:
    AppConfig           config_;        // 配置
    CenterRpcService    rpc_impl_;
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};

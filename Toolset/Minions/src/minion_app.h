/**
 *  @file   minion_app.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  管理所有的机器人对象
 *
 */

#pragma once

#include <string>
#include <unordered_map>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include "Singleton.h"
#include "minion.h"
#include "script/script_rt.h"


class MinionApp : public Singleton<MinionApp>
{
public:
    MinionApp();
    ~MinionApp();

    bool Init(const std::string& file);

    // 开始启动
    bool Run();

    // 机器人对象的创建的销毁
    MinionPtr   CreateMinion(const std::string& host, int16_t port);
    void        DestroyMinion(Minion* ptr);

    boost::asio::io_service&    GetIOService() {return io_service_;}

public:
    // 网络事件回调
    void    OnTcpError(size_t, TcpClientPtr, const bs::error_code&);
    void    OnTcpConnect(size_t, TcpClientPtr, const std::string&, int16_t);
    void    OnTcpRead(size_t, TcpClientPtr, size_t);

private:
    // 提供I/O服务的完成端口对象(Windows实现)
    boost::asio::io_service     io_service_;

    // lua虚拟机
    ScriptRuntime   script_;

    // 所有的机器人
    std::unordered_map<size_t, MinionPtr>   minion_list_;

    // 机器人标识符
    size_t     current_id_; 
};

// 仅有一个io_service对象
inline boost::asio::io_service&  GetIOService()
{
    return MinionApp::GetInst().GetIOService();
}

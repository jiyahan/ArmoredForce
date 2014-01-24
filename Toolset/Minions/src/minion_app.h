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
#include "minion.h"
#include "script/script_rt.h"



class MinionApp : boost::noncopyable
{
public:
    MinionApp();
    ~MinionApp();

    // 开始启动
    bool Start(const std::string& script);

    // 机器人对象的创建的销毁
    Minion* CreateMinion(const std::string& host, int16_t port);
    void    DestroyMinion(Minion* ptr);

public:
    // 网络事件回调
    void    OnTcpError(size_t, TcpClientPtr, const bs::error_code&);
    void    OnTcpConnect(size_t, TcpClientPtr, const std::string&, int16_t);
    void    OnTcpRead(size_t, TcpClientPtr, size_t);

private:
    // 机器人标识符
    size_t     current_id_; 

    // 所有的机器人
    std::unordered_map<size_t, Minion*>   minion_list_;

    // lua虚拟机
    ScriptRuntime   script_;

    // io_service对象(即I/O Completion Port)
    boost::asio::io_service     io_service_;
};

bool        CreateApp();
MinionApp&  GetApp();
void        DestroyApp();

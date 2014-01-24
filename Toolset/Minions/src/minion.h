/**
 *  @file   minion.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  单个机器人对象
 *
 */

#pragma once

#include <memory>
#include "net/tcp_client.h"

namespace electron {class CMessage;}

class Minion : boost::noncopyable
{
public:
    explicit Minion(TcpClientPtr ptr);
    ~Minion();

    // 发送消息给服务器
    void    Write(electron::CMessage* msg);

    // 发起读取消息请求
    void    Read();

    size_t  GetID() const {return id_;}
    void    SetID(size_t id) {id_ = id;}

private:
    // 唯一标识符
    size_t          id_;

    // TCP连接
    TcpClientPtr    tcp_conn_;
};

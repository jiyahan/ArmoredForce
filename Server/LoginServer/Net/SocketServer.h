#pragma once

#include <string>
#include <boost/noncopyable.hpp>
#include <atom/CAtom.h>
#include <electron/CElectron.h>


using namespace electron;
using namespace atom;


class SocketServer : boost::noncopyable
{
public:
    enum { LISTEN_THREAD_NUM = 1};
public:
    SocketServer(void);	
    ~SocketServer(void);

    bool Start(const std::string& host, U16 port);

    void Stop();

    //发送消息
    void Send(U64 connector, CMessage& msg);

    void Close(U64 connector);

    //获取SOCKETMESSAGE
    CMessageQueueControllerSetBind GetSocketMessage();

    std::string GetPeerAddress(U64 connector);

private:
    U64             listener_;
    CObjectPtr      msg_queue_;
};


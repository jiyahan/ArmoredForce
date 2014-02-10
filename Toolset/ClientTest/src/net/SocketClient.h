#pragma once

#include <boost/noncopyable.hpp>
#include "atom/CAtom.h"
#include "electron/CElectron.h"


using namespace atom;
using namespace electron;


class SocketClient : private boost::noncopyable
{
public:
    enum { THREAD_AMOUNT = 1 };
public:
    SocketClient();
    ~SocketClient();

    bool Start(const std::string& host, U16 port);

    bool ResetConnection(const std::string& host, U16 port);

    void Close();

    void Send(CMessage& msg);

    U64  GetID() {return client_id_;}

    CMessageQueueControllerSetBind GetSocketMessage();

private:
    bool RegisterEvent();
    bool Connect(const std::string& host, U16 port);

private:
    U64             client_id_;
    CObjectPtr      msg_queue_;
};


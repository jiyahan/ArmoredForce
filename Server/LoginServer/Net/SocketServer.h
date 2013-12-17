#pragma once

#include <string>
#include <boost/noncopyable.hpp>
#include <atom/CAtom.h>
#include <electron/CElectron.h>



class SocketServer : boost::noncopyable
{
public:
	SocketServer(void);	
	~SocketServer(void);

	bool Start(const std::string& host, U16 port);

	void Close();

	//获取SOCKETMESSAGE
	void GetSocketMessage(CMessageQueueControllerSetBind& msg);

	//发送消息
	void Send(U64 connector, CMessage& msg);

    template <typename T>
    void Send(U64 connector, U32 msgid, const T& data)
    {
        CMessage msg(msgid);
        msg << data;
        Send(connector, msg);
    }

	void CloseAConnection(U64 connector);

private:
    U64           listener_;
    CObjectPtr    msg_queue_;
};


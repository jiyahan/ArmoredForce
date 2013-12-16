#pragma once

#include <boost/noncopyable.hpp>
#include "atom/CAtom.h"
#include "electron/CElectron.h"


using namespace atom;
using namespace electron;

#include "../../../common/MSGCode.h"


class SocketClient : boost::noncopyable
{
public:
	SocketClient(void);
	~SocketClient(void);

	bool Start(const char* ip, U16 port);

	void Close();

	void Send(CMessage& msg);

    template <typename T>
    void Send(U32 msgID, const T& data)
    {
        CMessage msg(msgID);
        msg << data;
        Send(msg);
    }

	void GetSocketMessage(CMessageQueueControllerSetBind &messages);

private:
    U64             client_id_;
    CObjectPtr      msg_queue_;
};


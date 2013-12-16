#include "StdAfx.h"
#include "MsgProcess.h"
#include "GameServer.h"
#include "../../common/RoleCommon.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"
#include <allocators>

using namespace std;


// ´¦Àí½ÇÉ«µÇÂ¼
void HandleUserAuth(CMessage& msg)
{
	MSGAccountAuthorize request;
	msg >> request;
	cout << request.device << "\t" << request.deviceType << "\t"
        << request.account << "\t" << request.usrsign << endl;

    MSGAccountAuthorizeResponse response;
    response.roleId = 1000;
    RoleCommon role = {"hello"};
    CArchive archive;
    archive << role;
    archive.Clone(response.data);

    CMessage msg2(MID_ACCOUNT_AUTHORIZE_RESPOND);
    msg2.Write(response.data.GetLength());
    msg2.Write(response.data, response.data.GetLength());
	GameServer::GetInstance().GetSocketServer().Send(msg.GetConnector(), msg2);
}

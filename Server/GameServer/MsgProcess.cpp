#include "stdafx.h"
#include "MsgProcess.h"
#include "GameServer.h"
#include "../../common/RoleCommon.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"


using namespace std;

GameServer& thisServer = GameServer::GetInstance();

// ´¦Àí½ÇÉ«µÇÂ¼
void HandleUserAuth(CMessage& msg)
{
	MSGAccountAuthorize request;
	msg >> request;
	cout << request.device << "\t" << request.deviceType << "\t"
        << request.account << "\t" << request.usrsign << endl;

    RoleCommon role = {"role-name"};
    MSGAccountAuthorizeResponse response;
    response.roleId = 1000;
    
    CArchive archive;
    archive << role;
    archive.Clone(response.data);

	thisServer.GetSocketServer().Send(msg.GetConnector(), MID_ACCOUNT_AUTHORIZE_RESPOND, response);
}

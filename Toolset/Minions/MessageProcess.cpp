#include "StdAfx.h"
#include "MessageProcess.h"
#include "../../common/MESSAGE_ID.h"
#include "../../common/MSGCode.h"
#include "../../common/MSGGame.h"
#include "../../common/MSGLogin.h"

using namespace std;


void HandleLoginResponse(CMessage& msg)
{
    MSGLoginLoginResponse response;
    msg >> response;
    cout << "result: " << response.result 
        << " signature: " << response.sign << endl;
}

void HandleVerifyResponse(CMessage& msg)
{
    MSGLoginVersionVerifyResponse responce;
    msg >> responce;
    cout << "result: " << responce.result << endl;

}
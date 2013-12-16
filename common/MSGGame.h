#ifndef CHGAME_MSGGame_H
#define CHGAME_MSGGame_H

// linux下仅支持`/`作为路径分隔符
#include "MESSAGE_ID.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace std;
using namespace atom;


//账号验证
struct MSGAccountAuthorize
{
	static const NOVA_MESSAGE_ID msgId=MID_ACCOUNT_AUTHORIZE_REQUEST;
	// device  info;
	a_string device ;         
	// device  type;
	a_string deviceType ;     
	// account info;
	a_string account; 
	// user signature;
	a_string usrsign; 
};

struct MSGAccountAuthorizeResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_ACCOUNT_AUTHORIZE_RESPOND;
	//0成功1失败
	bool result;
	//玩家唯一ID
	U64	roleId;
	//玩家数据
	CMemory data;
	
};

template<class Archive>
inline void Serialize(Archive & archive, MSGAccountAuthorize & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.device );
	archive.Bind( value.deviceType );
	archive.Bind(value.account);
	archive.Bind(value.usrsign);	
}


template<class Archive>
inline void Serialize(Archive & archive, MSGAccountAuthorizeResponse & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.result);
	archive.Bind(value.roleId);
	archive.Bind(value.data);
}

#endif
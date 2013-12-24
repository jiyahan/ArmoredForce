#ifndef CHGAME_MSGGame_H
#define CHGAME_MSGGame_H

#include "Config.h"
#include "MESSAGE_ID.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace std;
using namespace atom;


//账号验证
struct MSGAccountAuthorize
{
	static const NOVA_MESSAGE_ID msgId=MID_ACCOUNT_AUTHORIZE_REQUEST;
	// device  info;
	String device ;         
	// device  type;
	String deviceType ;     
	// account info;
	String account; 
	// user signature;
	String usrsign; 
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

//战斗pve请求
struct MSGBattleCombat
{
	static const NOVA_MESSAGE_ID msgId=MID_CHARACTER_INSTANCE_COMBAT_REQUEST;	
	//目标位置
	U08 mapId;
	//目标相对位置
	U08 posId;
};

//战斗pve请求返回
struct MSGBattleCombatResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_CHARACTER_INSTANCE_COMBAT_RESPOND;
	//0成功
	bool result;
	//战斗数据
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


template<class Archive>
inline void Serialize(Archive & archive, MSGBattleCombat & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind(value.mapId);
	archive.Bind(value.posId);
}


template<class Archive>
inline void Serialize(Archive & archive, MSGBattleCombatResponse & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.result );
	archive.Bind( value.data );
}


#endif
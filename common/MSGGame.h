#ifndef CHGAME_MSGGame_H
#define CHGAME_MSGGame_H

#include "Config.h"
#include "MESSAGE_ID.h"
#include "../3rdparty/atom/atom/catom.h"

using namespace std;
using namespace atom;


//�˺���֤
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
	//0�ɹ�1ʧ��
	bool result;
	//���ΨһID
	U64	roleId;
	//�������
	CMemory data;
	
};

//ս��pve����
struct MSGBattleCombat
{
	static const NOVA_MESSAGE_ID msgId=MID_CHARACTER_INSTANCE_COMBAT_REQUEST;	
	//Ŀ��λ��
	U08 mapId;
	//Ŀ�����λ��
	U08 posId;
};

//ս��pve���󷵻�
struct MSGBattleCombatResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_CHARACTER_INSTANCE_COMBAT_RESPOND;
	//0�ɹ�
	bool result;
	//ս������
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
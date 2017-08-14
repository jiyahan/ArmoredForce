#ifndef CHGAME_MSGLogig_H
#define CHGAME_MSGLogin_H

#include "Config.h"
#include "../3rdParty/atom/electron/CElectron.h"
#include "MESSAGE_ID.h"

using namespace std;
using namespace electron;


//ע���˺�
struct MSGLoginRegist
{
	a_string account;
	a_string password;
	a_string email;
};

//ע���˺ŷ���
struct MSGLoginRegistResponse
{
	a_string account;
	//0�ɹ�1ʧ��
	I08 result;
};

//�˺ŵ�½
struct 	MSGLoginLogin
{	
	static const NOVA_MESSAGE_ID msgId=MID_LOGIN_LOGIN;
	a_string account;
	a_string password;
};

//�˺ŵ�½����
struct 	MSGLoginLoginResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_LOGIN_LOGINRESPONSE;
	//��֤��
	a_string sign;
	//0�ɹ�1ʧ��
	I08 result;
};

//������ɫ
struct 	MSGLoginCreate
{
	I32 areaId;
	a_string account;
};

//������ɫ����
struct 	MSGLoginCreateResponse
{
	I32 areaId;
	a_string account;
	//0�ɹ�1ʧ��
	I08 result;
};


//�汾��֤
struct MSGLoginVersionVerify
{
	static const NOVA_MESSAGE_ID msgId=MID_VERSION_VERIFY;
	I32 major;
	I32 minor;
};

//�汾��֤����
struct MSGLoginVersionVerifyResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_VERSION_VERIFYRESPONSE;
	//0�ɹ�1��Ч�汾
	U08 result;
    
    // ������Ϣ
    CMemory server_area;
};



template<class Archive>
inline void Serialize(Archive & archive, MSGLoginRegist & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.account );
	archive.Bind( value.password );
	archive.Bind(value.email);
}

template<class Archive>
inline void Serialize(Archive & archive, MSGLoginRegistResponse & value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.account );
    archive.Bind( value.result );    
}

template<class Archive>
inline void Serialize(Archive & archive, MSGLoginLogin & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.account );
	archive.Bind( value.password );
}

template<class Archive>
inline void Serialize(Archive & archive, MSGLoginLoginResponse & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.result );
	archive.Bind( value.sign );
}

template<class Archive>
inline void Serialize(Archive & archive, MSGLoginVersionVerify & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.major );
	archive.Bind( value.minor );
}

template<class Archive>
inline void Serialize(Archive & archive, MSGLoginVersionVerifyResponse & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.result );
	archive.Bind(value.server_area);
}

#endif
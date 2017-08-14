#ifndef CHGAME_MSGLogig_H
#define CHGAME_MSGLogin_H

// linux�½�֧��`/`��Ϊ·���ָ���
#include "../3rdparty/atom/electron/celectron.h"
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
	int areaId;
	string account;
};

//������ɫ����
struct 	MSGLoginCreateResponse
{
	int areaId;
	string account;
	//0�ɹ�1ʧ��
	I08 result;
};




//�汾��֤
struct MSGLoginVersionVerify
{
	static const NOVA_MESSAGE_ID msgId=MID_VERSION_VERIFY;
	int major;
	int minor;
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
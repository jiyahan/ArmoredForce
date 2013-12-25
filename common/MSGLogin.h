#ifndef CHGAME_MSGLogig_H
#define CHGAME_MSGLogin_H

#include "Config.h"
#include "../3rdparty/atom/electron/CElectron.h"
#include "MESSAGE_ID.h"

using namespace std;
using namespace electron;


//注册账号
struct MSGLoginRegist
{
	a_string account;
	a_string password;
	a_string email;
};

//注册账号返回
struct MSGLoginRegistResponse
{
	a_string account;
	//0成功1失败
	I08 result;
};

//账号登陆
struct 	MSGLoginLogin
{	
	static const NOVA_MESSAGE_ID msgId=MID_LOGIN_LOGIN;
	a_string account;
	a_string password;
};

//账号登陆返回
struct 	MSGLoginLoginResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_LOGIN_LOGINRESPONSE;
	//验证码
	a_string sign;
	//0成功1失败
	I08 result;
};

//创建角色
struct 	MSGLoginCreate
{
	int areaId;
	a_string account;
};

//创建角色返回
struct 	MSGLoginCreateResponse
{
	int areaId;
	a_string account;
	//0成功1失败
	I08 result;
};


//版本验证
struct MSGLoginVersionVerify
{
	static const NOVA_MESSAGE_ID msgId=MID_VERSION_VERIFY;
	int major;
	int minor;
};

//版本验证返回
struct MSGLoginVersionVerifyResponse
{
	static const NOVA_MESSAGE_ID msgId=MID_VERSION_VERIFYRESPONSE;
	//0成功1无效版本
	U08 result;
    
    // 区服信息
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
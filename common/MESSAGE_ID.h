#ifndef CHGAME_MESSAGE_ID_H
#define CHGAME_MESSAGE_ID_H

#include "Setting.inl"


enum NOVA_MESSAGE_ID
{
	MID_ACCOUNT_AUTHORIZE_REQUEST = NOVA_MESSAGE_ID_BEGIN,

	// 登录
	MID_LOGIN_LOGIN,

	// 登录返回
	MID_LOGIN_LOGINRESPONSE,

	//版本验证
	MID_VERSION_VERIFY,

	//版本验证返回
	MID_VERSION_VERIFYRESPONSE,

    // 注册
    MID_LOGIN_REGISTER,

    // 注册返回
    MID_LOGIN_REGISTER_RESPONSE,

	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_ACCOUNT_AUTHORIZE_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_ACCOUNT_DUPLICATE_LOGIN,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_OUT_OF_SYNC,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_REFRESH_CHARACTER_PROPERTIES,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_POSITION,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_BUILD,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_UPGRADE,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_CANCEL,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_FINISH,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_CONSTRUCTURE_REMOVE,



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RESOURCE_COLLECT,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RESOURCE_EXCHANGE,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_HOMEGRID_UPDATE,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_TRAIN,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_CANCEL_TRAIN,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_FINISH_TRAIN,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_RESEARCH,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_CANCEL_RESEARCH,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_FINISH_RESEARCH,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_MILITARY_USE_ARMY,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BATTLE_SEARCH_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BATTLE_SEARCH_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BATTLE_SEARCH_ABANDON,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BATTLE_COMBAT_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BATTLE_COMBAT_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_SET_NAME,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_VISIT_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_VISIT_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_REVENAGE_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_REVENAGE_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_PURCHASE_SHIELD,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_IAP_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_IAP_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BUY_WORKER_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_BUY_WORKER_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RANKING_AWARD_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RANKING_AWARD_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RANKING_FRESH_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_RANKING_FRESH_RESPOND,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_INSTANCE_COMBAT_REQUEST,


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	MID_CHARACTER_INSTANCE_COMBAT_RESPOND,

}; 

#endif

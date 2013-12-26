#ifndef CHGAME_Battle_H
#define CHGAME_Battle_H

#include "../Config.h"
#include "../../3rdParty/atom/atom/CAtom.h"

using namespace atom;




//角色弟子基本数据
struct tagBattleRoleOfficer
{
	//名字
	a_string id;
    //当前攻击力
    U32 attack;
	//等级
	U08 level;
	//位置
	U32 pos;
	//hp
	U32 hp;
};

//战斗结果
struct tagBattleResult
{
	//0胜利1失败2平局
	U08 result;
	//攻方掉血
	U32	attackerLoseHP;
	//守方掉血
	U32 defenderLoseHP;
	//评分
	U08	score;
};

//战斗奖励
struct tagBattlePrize
{
	//奖励类型
	U08 type;
	//类型编号
	U32	typeId;
	//类型数量
	U32	typeNumber;
};

//被攻击目标数据
struct tagBattleObject
{
	//被攻击位置ID
	U08 pos;
	//伤害值
	U32 loseHP;
	//目标弟子剩余hp
	U32 remainHP;
};

//战斗过程
struct tagBattleStep
{
	//发动方1左2右
	U08 attacker;
	//位置编号
	U08 pos;
	//技能编号
	U32	skill;
	//是否暴击0否1是
	U08	crit;
	//被伤害弟子个数
	vector<tagBattleObject> objs;
};

//战斗回合
struct tagBattleRound
{
	//战斗过程列表
	vector<tagBattleStep> steps;
};

//角色基本数据
struct tagBattleRole
{
	//名字
	a_string name;
	//等级
	U08 level;
	//hp
	U32 hp;
	//头像
	U32 pic;
	//角色弟子列表
	vector<tagBattleRoleOfficer> officers;
};

//战斗数据
struct tagBattle
{
	//攻击方
	tagBattleRole attacker;
	//防守方
	tagBattleRole defender;
	//结果 
	tagBattleResult result;
	//奖励
	vector<tagBattlePrize> prize;
	//过程
	vector<tagBattleRound> rounds;
};

template<class Archive>
inline void Serialize(Archive & archive, tagBattleRole & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.name );
	archive.Bind( value.level );
	archive.Bind(value.hp);
	archive.Bind(value.pic);
}

template<class Archive>
inline void Serialize(Archive & archive, tagBattleRoleOfficer & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.id );
	archive.Bind( value.attack );
	archive.Bind( value.level );
	archive.Bind(value.pos);
	archive.Bind(value.hp);
}

template<class Archive>
inline void Serialize(Archive & archive, tagBattle & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.attacker );
	archive.Bind( value.defender );
	archive.Bind( value.result );
	archive.Bind( value.prize );
    archive.Bind( value.rounds );
}


template<class Archive>
inline void Serialize(Archive & archive, tagBattleResult & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.result );
	archive.Bind( value.attackerLoseHP );
	archive.Bind( value.defenderLoseHP );
	archive.Bind( value.score );
}

template<class Archive>
inline void Serialize(Archive & archive, tagBattlePrize & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.type );
	archive.Bind( value.typeId );
	archive.Bind( value.typeNumber );
}

template<class Archive>
inline void Serialize(Archive & archive, tagBattleStep & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.attacker );
	archive.Bind( value.pos );
	archive.Bind( value.skill );
	archive.Bind( value.crit );
	archive.Bind( value.objs );
}


template<class Archive>
inline void Serialize(Archive & archive, tagBattleObject & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.pos );
	archive.Bind( value.loseHP );
	archive.Bind( value.remainHP );
}

template<class Archive>
inline void Serialize(Archive & archive, tagBattleRound & value, bool isSave)
{
	UNREFERENCED_PARAMETER(isSave);
	archive.Bind( value.steps );
}
#endif
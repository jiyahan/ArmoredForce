#ifndef CHGAME_Battle_H
#define CHGAME_Battle_H

#include "../Config.h"
#include "../../3rdParty/atom/atom/CAtom.h"

using namespace atom;




//��ɫ���ӻ�������
struct tagBattleRoleOfficer
{
	//����
	a_string id;
    //��ǰ������
    U32 attack;
	//�ȼ�
	U08 level;
	//λ��
	U32 pos;
	//hp
	U32 hp;
};

//ս�����
struct tagBattleResult
{
	//0ʤ��1ʧ��2ƽ��
	U08 result;
	//������Ѫ
	U32	attackerLoseHP;
	//�ط���Ѫ
	U32 defenderLoseHP;
	//����
	U08	score;
};

//ս������
struct tagBattlePrize
{
	//��������
	U08 type;
	//���ͱ��
	U32	typeId;
	//��������
	U32	typeNumber;
};

//������Ŀ������
struct tagBattleObject
{
	//������λ��ID
	U08 pos;
	//�˺�ֵ
	U32 loseHP;
	//Ŀ�����ʣ��hp
	U32 remainHP;
};

//ս������
struct tagBattleStep
{
	//������1��2��
	U08 attacker;
	//λ�ñ��
	U08 pos;
	//���ܱ��
	U32	skill;
	//�Ƿ񱩻�0��1��
	U08	crit;
	//���˺����Ӹ���
	vector<tagBattleObject> objs;
};

//ս���غ�
struct tagBattleRound
{
	//ս�������б�
	vector<tagBattleStep> steps;
};

//��ɫ��������
struct tagBattleRole
{
	//����
	a_string name;
	//�ȼ�
	U08 level;
	//hp
	U32 hp;
	//ͷ��
	U32 pic;
	//��ɫ�����б�
	vector<tagBattleRoleOfficer> officers;
};

//ս������
struct tagBattle
{
	//������
	tagBattleRole attacker;
	//���ط�
	tagBattleRole defender;
	//��� 
	tagBattleResult result;
	//����
	vector<tagBattlePrize> prize;
	//����
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
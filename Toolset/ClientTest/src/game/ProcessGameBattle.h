/**
 *  @file   ProcessGameBattle.h
 *  @author chenqiang01@7aurora.cm
 *  @date   Jan 21, 2014
 *  @brief  处理游戏逻辑的消息
 */


// forward declaration
namespace electron {class CMessage;}


void HandleCombatResponse(electron::CMessage& msg);

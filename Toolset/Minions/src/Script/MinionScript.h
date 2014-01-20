/**
 *  @file   Minion.h
 *  @date   Jan 20, 2014
 *  @author chenqiang01@7aurora.com
 *  @brief  
 */

#pragma once

struct lua_State;
namespace electron {class CMessage;}


//
bool MinionInit(lua_State* L);

//
void MinionSend(int32_t id, electron::CMessage* msg);

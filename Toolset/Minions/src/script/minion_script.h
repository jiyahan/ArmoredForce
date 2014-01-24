/**
 * @file    minion_script.h
 * @author  chenqiang01@7aurora.com
 * @date    Jan 21, 2014
 * @brief   封装机器人为lua对象
 */

#pragma once

struct lua_State;


#define  MINION_META_HANDLE      "Minion*.GC"


bool InitMinionScript(lua_State* L);

/**
 *  @file   script_rt.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  Lua script runtime
 *
 */

#pragma once

#include <boost/noncopyable.hpp>

struct lua_State;


class ScriptRuntime
{
public:

    static bool Init();

    static void Release();

    static lua_State* GetState() {return state_;}

    static bool DoFile(const char* filename);

    static bool Call(const char* func);
    
    // garbage collection
    static int PerformGC(bool full = false);

private:
    static lua_State*  state_;
};
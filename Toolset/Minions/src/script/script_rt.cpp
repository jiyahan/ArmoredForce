#include "script_rt.h"
#include <lua.hpp>
#include "minion_script.h"

lua_State*  ScriptRuntime::state_ = NULL;


bool ScriptRuntime::Init()
{
    state_ = luaL_newstate();
    luaL_openlibs(state_);
    InitMinionScript(state_);
    return true;
}

void ScriptRuntime::Release()
{
    if (state_)
    {
        lua_close(state_);
        state_ = NULL;
    }
}

bool ScriptRuntime::DoFile(const char* filename)
{
    CHECK(state_ && filename);
    bool ok = (luaL_dofile(state_, filename) == 0);
    if (!ok)
    {
        LOG(ERROR) << lua_tostring(state_, -1);
    }
    return ok;
}

bool ScriptRuntime::Call(const char* func)
{
    CHECK(func);
    int top = lua_gettop(state_);
    lua_getglobal(state_, func);
    if (lua_pcall(state_, 0, LUA_MULTRET, 0) != 0)
    {
        LOG(ERROR) << lua_tostring(state_, -1);
        lua_pop(state_, 1);
        return false;
    }
    return true;
}

int ScriptRuntime::PerformGC(bool full /*= false*/)
{
    if(!full) 
    {
        return lua_gc(state_, LUA_GCCOLLECT, 0);
    }
    int ret = 0;
    int old_count = 0;
    int count = lua_gc(state_, LUA_GCCOUNT, 0);
    while(old_count != count) 
    {
        ret = lua_gc(state_, LUA_GCCOLLECT, 0);
        old_count = count;
        count = lua_gc(state_, LUA_GCCOUNT, 0);
    }
    return ret;
}

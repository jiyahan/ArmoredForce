#include "LuaVM.h"
#include <easylogging++.h>


LuaVM::LuaVM()
    : owner_(true)
{
    state_ = luaL_newstate();
}


LuaVM::LuaVM(lua_State* L)
    : owner_(false)
{
    CHECK(L);
    state_ = L;
}


LuaVM::~LuaVM()
{
    if (owner_)
    {
        lua_close(state_);
        state_ = NULL;
    }
}

int LuaVM::OnError()
{
    const char* err_msg = lua_tostring(state_, -1);
    fprintf(stderr, "%s", err_msg);
    return 0;
}

bool LuaVM::LoadFile(const char* filename)
{
    CHECK(state_ && filename);
    bool ok = (luaL_loadfile(state_, filename) == 0);
    if (!ok)
    {
        OnError();
    }
    return ok;
}

bool LuaVM::DoFile(const char* filename)
{
    CHECK(state_ && filename);
    bool ok = (luaL_dofile(state_, filename) == 0);
    if (!ok)
    {
        OnError();
    }
    return ok;
}

bool LuaVM::LoadString(const std::string& s)
{
    CHECK(state_);
    bool ok = (luaL_loadstring(state_, s.data()) == 0);
    if (!ok)
    {
        OnError();
    }
    return ok;
}

bool LuaVM::DoString(const std::string& s)
{
    CHECK(state_);
    bool ok = (luaL_dostring(state_, s.data()) == 0);
    if (!ok)
    {
        OnError();
    }
    return ok;
}

bool LuaVM::Call(int params /* = 0 */, int results /* = LUA_MULTRET */)
{
    bool ok = (lua_pcall(state_, params, results, 0) == 0);
    if (!ok)
    {        
        OnError();
    }
    return ok;
}

bool LuaVM::Call(const char* func, const char* fmt, ...)
{
    CHECK(func);
    GetGlobal(func);
    return Call(0, LUA_MULTRET);
}

int LuaVM::PerformGC(bool full /*= false*/)
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


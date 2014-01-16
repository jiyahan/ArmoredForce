#include "LuaState.h"
#include <lobject.h>
#include <lgc.h>

LuaState::LuaState()
{
    state_ = luaL_newstate();
}

LuaState(lua_State* L)
{
}

LuaState::~LuaState()
{
    if (G(state_)->mainthread == state_)
    {
        lua_close(state_);
    }
}



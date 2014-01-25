#include "minion_script.h"
#include <lua.hpp>
#include <unordered_map>
#include <electron/message/CMessage.h>
#include "msg_script.h"
#include "../timer.h"
#include "../minion.h"
#include "../minion_app.h"


using namespace electron;

#define check_minion(L)     ((Minion**)luaL_checkudata(L, 1, MINION_META_HANDLE))

namespace {

int minion_gc(lua_State* L)
{
    Minion** pptr = check_minion(L);
    GetApp().DestroyMinion(*pptr);
    *pptr = NULL;
    return 0;
}

int minion_tostring(lua_State* L)
{
    Minion** pptr = check_minion(L);
    lua_pushfstring(L, "Minion* (%p)", *pptr);
    return 1;
}

int minion_id(lua_State* L)
{
    Minion** pptr = check_minion(L);
    if (*pptr)
    {
        lua_pushinteger(L, (*pptr)->GetID());
        return 1;
    }
    return 0;
}


int minion_send(lua_State* L)
{
    Minion** pptr = check_minion(L);
    CMessage* msg = *((CMessage**)luaL_checkudata(L, 2, MSG_META_HANDLE));
    if (*pptr && msg)
    {
        (*pptr)->Write(msg);
    }
    return 0;
}

int new_minion(lua_State* L)
{
    const char* host = luaL_checkstring(L, 1);
    int16_t port = luaL_checkinteger(L, 2);
    Minion* ptr = GetApp().CreateMinion(host, port);
    if (ptr == NULL)
    {
        luaL_error(L, "create minion failed.");
        return 0;
    }
    lua_pushinteger(L, ptr->GetID());
    void* udata = lua_newuserdata(L, sizeof(ptr));
    memcpy(udata, &ptr, sizeof(ptr));
    luaL_getmetatable(L, MINION_META_HANDLE);
    lua_setmetatable(L, -2);
    return 2;
}

// 建立元表
void make_meta(lua_State *L) 
{
    static const luaL_Reg meta_lib[] = 
    {
        {"__gc", minion_gc },
        {"__tostring", minion_tostring },
        {"id", minion_id},
        {"send", minion_send},
        { NULL, NULL },
    };

    luaL_newmetatable(L, MINION_META_HANDLE);   /* create metatable for file handles */
    lua_pushvalue(L, -1);                       /* push metatable */
    lua_setfield(L, -2, "__index");             /* metatable.__index = metatable */
    luaL_register(L, NULL, meta_lib);           /* add file methods to new metatable */
}

//////////////////////////////////////////////////////////////////////////

std::unordered_map<int32_t, TimerPtr>   g_timer_pool;

void timer_handle(TimerPtr tp)
{

}

int start_timer(lua_State* L)
{
    if (lua_isfunction(L, -1))
    {
        luaL_error(L, "not function");
        return 0;
    }

    return 1;
}

} // anonymous namespace


bool InitMinionScript(lua_State* L)
{
    make_meta(L);
    lua_register(L, "new_minion", new_minion);
    return true;
}

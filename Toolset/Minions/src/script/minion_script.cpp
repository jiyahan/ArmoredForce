#include "minion_script.h"
#include <lua.hpp>
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
    MinionApp::GetInst().DestroyMinion(*pptr);
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
    MinionPtr ptr = MinionApp::GetInst().CreateMinion(host, port);
    if (ptr == NULL)
    {
        luaL_error(L, "create minion failed.");
        return 0;
    }
    lua_pushinteger(L, ptr->GetID());
    Minion* raw_ptr = ptr.get();
    void* udata = lua_newuserdata(L, sizeof(raw_ptr));
    memcpy(udata, &raw_ptr, sizeof(raw_ptr));
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

void timer_handle(lua_State* L, TimerPtr tp)
{
    lua_rawgeti(L, LUA_REGISTRYINDEX, tp->GetID());
    lua_pushinteger(L, tp->GetID());
    if (lua_pcall(L, 1, LUA_MULTRET, 0) != 0)
    {
        LOG(ERROR) << lua_tostring(L, -1);
    }
}

int create_timer(lua_State* L)
{    
    if (!lua_isfunction(L, -1))
    {
        luaL_error(L, "type is not function");
        return 0;
    }

    int milsec = luaL_checkinteger(L, -2);
    int ref = luaL_ref(L, LUA_REGISTRYINDEX);
    if (ref == LUA_REFNIL)
    {
        return 0;
    }
    
    TimerPtr tp = Timer::Create(ref);
    if (!tp)
    {
        return 0;
    }
    tp->Associate(std::bind(timer_handle, L, tp));
    tp->ExpireAfter(milsec);
    lua_pushinteger(L, ref);
    return 1;
}

int destroy_timer(lua_State* L)
{
    int ref = luaL_checkinteger(L, -1);
    luaL_unref(L, LUA_REGISTRYINDEX, ref);
    Timer::Destroy(ref);
    return 0;
}

} // anonymous namespace


bool InitMinionScript(lua_State* L)
{
    make_meta(L);
    lua_register(L, "new_minion", new_minion);
    lua_register(L, "create_timer", create_timer);
    lua_register(L, "destroy_timer", destroy_timer);
    return true;
}

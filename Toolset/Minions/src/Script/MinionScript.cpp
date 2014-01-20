#include "MinionScript.h"
#include <lua.hpp>
#include "../Net/SocketClient.h"

typedef SocketClient Minion;


#define MINION_HANDLE    "Minion*.GC"
#define check_minion(L)    ((Minion**)luaL_checkudata(L, 1, MINION_HANDLE))


static int new_minion(lua_State* L)
{
    Minion* ptr = new Minion;
    void* udata = lua_newuserdata(L, sizeof(ptr));
    memcpy(udata, &ptr, sizeof(ptr));
    luaL_getmetatable(L, MINION_HANDLE);
    lua_setmetatable(L, -2);
    return 1;
}

static int minion_gc(lua_State* L)
{
    Minion** ptr = check_minion(L);
    if (*ptr)
    {
        delete *ptr;
        *ptr = NULL;
    }
    return 0;
}

static int minion_tostring(lua_State* L)
{
    Minion** minion = check_minion(L);
    lua_pushfstring(L, "minion (%p)", *minion);
    return 1;
}

static int minion_id(lua_State* L)
{
    Minion** minion = check_minion(L);
    auto id = (*minion)->GetID();
    lua_pushnumber(L, static_cast<lua_Number>(id));
    return 1;
}

static int minion_connect(lua_State* L)
{
    Minion** ptr = check_minion(L);
    int args = lua_gettop(L);
    if (args < 3)
    {
        luaL_error(L, "minion:connect(host, port, [reconnect])");
        return 0;
    }

    string host = luaL_checkstring(L, 2);
    int16_t port = (int16_t)luaL_checkinteger(L, 3);
    bool result = false;
    bool reconnect = false;
    if (args == 4)
    {
        reconnect = true;
        reconnect = (lua_toboolean(L, 4) != 0);
    }
    if (!reconnect)
    {
        result = (*ptr)->Start(host, port);
    }
    else
    {
        result = (*ptr)->ResetConnection(host, port);
    }

    lua_pushboolean(L, result);
    return 1;
}


//////////////////////////////////////////////////////////////////////////

static void createmeta(lua_State *L) 
{
    static const luaL_Reg meta_lib[] = 
    {
        {"connect", minion_connect},
        {"get_id", minion_id},
        {"__gc", minion_gc},
        {"__tostring", minion_tostring},
        {NULL, NULL}
    };

    luaL_newmetatable(L, MINION_HANDLE);    /* create metatable for file handles */
    lua_pushvalue(L, -1);                   /* push metatable */
    lua_setfield(L, -2, "__index");         /* metatable.__index = metatable */
    luaL_register(L, NULL, meta_lib);       /* add file methods to new metatable */
}

bool minon_init(lua_State* L)
{
    createmeta(L);
    lua_register(L, "new_minion", new_minion);
    return true;
}

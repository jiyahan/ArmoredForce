#include "minion_script.h"
#include <lua.hpp>
#include "../minion.h"

#define MINION_META_HANDLE    "Minion*.GC"
#define check_message(L)    ((Robot**)luaL_checkudata(L, 1, ROBOT_META_HANDLE))


static int new_minion(lua_State* L)
{
    luaL_getmetatable(L, MINION_META_HANDLE);
    lua_setmetatable(L, -2);
    
    return 1;
}

static int minion_gc(lua_State* L)
{
    return 0;
}

static int minion_tostring(lua_State* L)
{
    return 0;
}

static void make_meta(lua_State *L) 
{
    static const luaL_Reg meta_lib[] = 
    {
        { "__gc", minion_gc },
        { "__tostring", minion_tostring },
        { NULL, NULL },
    };

    luaL_newmetatable(L, MINION_META_HANDLE);   /* create metatable for file handles */
    lua_pushvalue(L, -1);                       /* push metatable */
    lua_setfield(L, -2, "__index");             /* metatable.__index = metatable */
    luaL_register(L, NULL, meta_lib);           /* add file methods to new metatable */
}

bool InitMinionScript(lua_State* L)
{
    make_meta(L);
    lua_register(L, "new_minion", new_minion);
    return true;
}

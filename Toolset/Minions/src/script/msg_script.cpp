#include "msg_script.h"
#include <lua.hpp>
#include <string>
#include <vector>
#include <type_traits>
#include <boost/algorithm/string.hpp>
#include <electron/message/CMessage.h>

using namespace std;
using namespace electron;


#define check_message(L)    ((CMessage**)luaL_checkudata(L, 1, MSG_META_HANDLE))


namespace {

int8_t to_char(lua_State* L, int32_t index)
{
    int8_t bt = 0;
    if (lua_isstring(L, index))
    {
        const char* str = luaL_checkstring(L, index);
        if (!str || strlen(str) != 1)
        {
            luaL_error(L, "'%%c' expect 1 byte string, but get '%s'\n", str);
        }
    }
    else if (lua_isnumber(L, index))
    {
        bt = static_cast<int8_t>(luaL_checkinteger(L, index));
    }
    else if (lua_isboolean(L, index))
    {
        bt = static_cast<int8_t>(lua_toboolean(L, index));
    }
    else
    {
        luaL_error(L, "invalid type (%d) for char format.", lua_type(L, index));
    }
    
    return bt;
}

// 消息封包
void pack_format(CMessage* msg, lua_State* L, char fmt, int32_t index)
{
    assert(msg && L);
    switch(fmt)
    {
    case 'c':  // 1 byte char
        msg->Write(to_char(L, index));
        break;

    case 'h': // 2 bytes short
        msg->Write(static_cast<int16_t>(luaL_checkinteger(L, index)));
        break;

    case 'i': // 4 bytes int32_t
        msg->Write(static_cast<int32_t>(luaL_checkinteger(L, index)));
        break;

    case 'q': // 8 bytes int64
        msg->Write(static_cast<int64_t>(luaL_checknumber(L, index)));
        break;

    case 'f': // 4 bytes float
        msg->Write(static_cast<float>(luaL_checknumber(L, index)));
        break;

    case 'd': // 8 bytes double
        msg->Write(static_cast<double>(luaL_checknumber(L, index)));
        break;
        
    case 's':
        msg->Write(luaL_checkstring(L, index));
        break;

    default:
        luaL_error(L, "invalid format '%c'.", fmt);
    }
}

// 消息解包
void unpack_format(CMessage* msg, lua_State* L, char fmt)
{
    switch(fmt)
    {
    case 'c':
        lua_pushinteger(L, msg->ReadI08());
        break;

    case 'h':
        lua_pushinteger(L, msg->ReadI16());
        break;

    case 'i':
        lua_pushinteger(L, msg->ReadI16());
        break;

    case 'q':
        lua_pushnumber(L, static_cast<lua_Number>(msg->ReadU64()));
        break;

    case 'f':
        lua_pushnumber(L, msg->ReadFloat());
        break;

    case 'd':
        lua_pushnumber(L, msg->ReadDouble());
        break;

    case 's':
        {
            const auto& str = msg->ReadString();
            lua_pushstring(L, str.c_str());
        }
        break;

    default:
        luaL_error(L, "invalid format '%c'.", fmt);
        break;
    }
}


bool check_tokens(char ch)
{
    static const string tokens = "chiqfdsg";
    return tokens.find_first_of(ch) != string::npos;
}


//////////////////////////////////////////////////////////////////////////

int32_t new_message(lua_State* L)
{
    int32_t arg = lua_gettop(L);
    if (arg  < 1)
    {
        luaL_error(L, "Message.new(msg_type)");
        return 0;
    }
    
    int32_t msg_type = luaL_checkinteger(L, 1);
    CMessage* msg = new CMessage(msg_type);
    void* udata = lua_newuserdata(L, sizeof(msg));
    memcpy(udata, &msg, sizeof(msg));
    luaL_getmetatable(L, MSG_META_HANDLE);
    lua_setmetatable(L, -2);
    return 1;
}

int32_t message_gc(lua_State* L)
{
    CMessage** msg = check_message(L);
    if (*msg)
    {
        delete *msg;
        *msg = NULL;
    }
    return 0;
}

int32_t message_id(lua_State* L)
{
    CMessage** msg = check_message(L);
    if (*msg)
    {
        int16_t msg_type = (*msg)->GetCommandID();
        lua_pushinteger(L, msg_type);
        return 1;
    }
    return 0;
}

int32_t message_tostring(lua_State* L)
{
    CMessage** msg = check_message(L);
    lua_pushfstring(L, "Message* (%p)", *msg);
    return 1;
}

int32_t message_pack(lua_State* L)
{
    int32_t arg = lua_gettop(L);
    if (arg < 3)
    {
        luaL_error(L, "msg:pack(fmt, ...)");
        return 0;
    }
    CMessage** msg = check_message(L);
    string format = luaL_checkstring(L, 2);    

    vector<string> tokens;
    boost::split(tokens, format, boost::is_any_of("%"));
    int32_t start_index = 3;
    for (const auto& token : tokens)
    {
        if (!token.empty())
        {
            pack_format(*msg, L, token.at(0), start_index++);
        }
    }
    return 0;
}

int32_t message_unpack(lua_State* L)
{
    int32_t arg = lua_gettop(L);
    if (arg != 2)
    {
        luaL_error(L, "msg:unpack(fmt)");
        return 0;
    }
    CMessage** msg = check_message(L);
    string format = luaL_checkstring(L, 2);
    vector<string> tokens;
    boost::split(tokens, format, boost::is_any_of("%"));
    for (const auto& token : tokens)
    {
        char fmt = token.at(0);
        unpack_format(*msg, L, fmt);
    }
    return 0;
}

int32_t message_size(lua_State* L)
{
    CMessage** msg = check_message(L);
    assert(msg && *msg);
    CInterface<IImportable> import;
    if( import.Mount(*msg, IID_IMPORTABLE) ) 
    {
        lua_pushnumber(L, static_cast<lua_Number>(import->Available()));
        return 1;
    }
    return 0;
}

// 建立元表
void make_meta(lua_State *L) 
{
    static const luaL_Reg meta_lib[] = 
    {
        { "pack", message_pack },
        { "unpack", message_unpack },
        { "id", message_id},
        { "__len", message_size },
        { "__gc", message_gc },
        { "__tostring", message_tostring },
        { NULL, NULL },
    };

    luaL_newmetatable(L, MSG_META_HANDLE);  /* create metatable for file handles */
    lua_pushvalue(L, -1);                   /* push metatable */
    lua_setfield(L, -2, "__index");         /* metatable.__index = metatable */
    luaL_register(L, NULL, meta_lib);       /* add file methods to new metatable */
}

} // anonymous namespace


//////////////////////////////////////////////////////////////////////////
void InitMessageScript(lua_State* L)
{
    make_meta(L);
    lua_register(L, "new_message", new_message);
}

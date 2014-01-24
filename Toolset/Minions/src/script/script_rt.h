/**
 *  @file   script_rt.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  Lua虚拟机的简单抽象
 *
 */

#pragma once

#include <lua.hpp>
#include <boost/noncopyable.hpp>


class ScriptRuntime
{
public:
    static bool Init();
    static void Release();

    static lua_State* GetState() {return state_;}

    static int GetTop()             {return lua_gettop(state_);}
    static void SetTop(int index)   {return lua_settop(state_, index);}

    static void GetGlobal(const char* key) {lua_getglobal(state_, key);}

    static void Push(bool v)        {lua_pushboolean(state_, v);}
    static void Push(int8_t v)      {lua_pushinteger(state_, v);}
    static void Push(uint8_t v)     {lua_pushinteger(state_, v);}
    static void Push(int16_t v)     {lua_pushinteger(state_, v);}
    static void Push(uint16_t v)    {lua_pushinteger(state_, v);}
    static void Push(int32_t v)     {lua_pushinteger(state_, v);}
    static void Push(uint32_t v)    {lua_pushinteger(state_, v);}
    static void Push(int64_t v)     {lua_pushnumber(state_, static_cast<lua_Number>(v));}
    static void Push(uint64_t v)    {lua_pushnumber(state_, static_cast<lua_Number>(v));}
    static void Push(float v)       {lua_pushnumber(state_, v);}
    static void Push(double v)      {lua_pushnumber(state_, v);}
    static void Push(const char* s) {lua_pushstring(state_, s);}
    static void Push(void* v)       {lua_pushlightuserdata(state_, v);}

    // access functions (stack -> C)
    static int IsNumber(int index)        {return lua_isnumber(state_, index);}
    static int IsString(int index)        {return lua_isstring(state_, index);}
    static int IsCFunction(int index)     {return lua_iscfunction(state_, index);}
    static int IsUserData(int index)      {return lua_isuserdata(state_, index);}
    static int IsFunction(int index)      {return lua_isfunction(state_, index);}
    static int IsTable(int index)         {return lua_istable(state_, index);}
    static int IsLightUserData(int index) {return lua_islightuserdata(state_, index);}
    static int IsNil(int index)           {return lua_isnil(state_, index);}
    static int IsBoolean(int index)       {return lua_isboolean(state_, index);}
    static int IsThread(int index)        {return lua_isthread(state_, index);}
    static int IsNone(int index)          {return lua_isnone(state_, index);}
    static int IsNoneOrNil(int index)     {return lua_isnoneornil(state_, index);}
    static int Type(int index)            {return lua_type(state_, index);}
    static std::string TypeName(int type) {return lua_typename(state_, type);}

    static void NewUserData(const char* meta, void* data);
    static bool DoFile(const char* filename);
    static bool Call(const char* func);
    static bool Call(int params = 0, int results = LUA_MULTRET);
    
    // garbage collection
    static int PerformGC(bool full = false);

private:
    static lua_State*  state_;
};
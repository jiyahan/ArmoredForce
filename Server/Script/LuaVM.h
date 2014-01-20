/**
 *  @file   LuaState.h
 *  @author 
 *  @date   Jan 16, 2014
 *  @brief  Lua virtual machine, a lightweight lua_State wrapper.
 */

#pragma once

#include <lua.hpp>
#include <string>
#include <boost/noncopyable.hpp>


class LuaVM : boost::noncopyable
{
public:
    LuaVM();
    explicit LuaVM(lua_State* L);
    virtual ~LuaVM();

    int OnError();
    
    lua_State* GetState()       {return state_;}
    void OpenLibs()             {luaL_openlibs(state_);}

    int GetTop() const              {return lua_gettop(state_);}
    void SetTop(int index)          {return lua_settop(state_, index);}

    void GetGlobal(const char* key) {lua_getglobal(state_, key);}

    void Push(bool v)               {lua_pushboolean(state_, v);}
    void Push(int8_t v)             {lua_pushinteger(state_, v);}
    void Push(uint8_t v)            {lua_pushinteger(state_, v);}
    void Push(int16_t v)            {lua_pushinteger(state_, v);}
    void Push(uint16_t v)           {lua_pushinteger(state_, v);}
    void Push(int32_t v)            {lua_pushinteger(state_, v);}
    void Push(uint32_t v)           {lua_pushinteger(state_, v);}
    void Push(int64_t v)            {lua_pushnumber(state_, static_cast<lua_Number>(v));}
    void Push(uint64_t v)           {lua_pushnumber(state_, static_cast<lua_Number>(v));}
    void Push(float v)              {lua_pushnumber(state_, v);}
    void Push(double v)             {lua_pushnumber(state_, v);}
    void Push(const char* s)        {lua_pushstring(state_, s);}
    void Push(void* v)              {lua_pushlightuserdata(state_, v);}    

    // access functions (stack -> C)
    int IsNumber(int index) const       {return lua_isnumber(state_, index);}
    int IsString(int index) const       {return lua_isstring(state_, index);}
    int IsCFunction(int index) const    {return lua_iscfunction(state_, index);}
    int IsUserData(int index) const     {return lua_isuserdata(state_, index);}
    int IsFunction(int index) const     {return lua_isfunction(state_, index);}
    int IsTable(int index) const        {return lua_istable(state_, index);}
    int IsLightUserData(int index) const{return lua_islightuserdata(state_, index);}
    int IsNil(int index) const          {return lua_isnil(state_, index);}
    int IsBoolean(int index) const      {return lua_isboolean(state_, index);}
    int IsThread(int index) const       {return lua_isthread(state_, index);}
    int IsNone(int index) const         {return lua_isnone(state_, index);}
    int IsNoneOrNil(int index) const    {return lua_isnoneornil(state_, index);}
    int Type(int index) const           {return lua_type(state_, index);}
    std::string TypeName(int type)      {return lua_typename(state_, type);}

    lua_CFunction AtPanic(lua_CFunction f) {return lua_atpanic(state_, f);}

    bool LoadFile(const char* filename);
    bool DoFile(const char* filename);
    bool LoadString(const std::string& s);
    bool DoString(const std::string& s);

    bool Call(int params = 0, int results = LUA_MULTRET);
    bool Call(const char* func, const char* fmt = NULL, ...);
    
	// garbage collection
	int PerformGC(bool full = false);        

private:
    bool        owner_;
    lua_State*  state_;
};
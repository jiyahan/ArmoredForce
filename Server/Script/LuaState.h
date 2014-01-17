/**
 *  @file   LuaState.h
 *  @author 
 *  @date   Jan 16, 2014
 *  @brief  A lightweight lua_State wrapper.
 */

#pragma once

#include <lua.hpp>
#include <string>
#include <boost/noncopyable.hpp>


class LuaState : boost::noncopyable
{
public:
    LuaState();
    LuaState(lua_State* L);
    ~LuaState();

    lua_CFunction AtPanic(lua_CFunction f) {return lua_atpanic(state_, f);}
    void OpenLibs();


    int GetTop() const          {return lua_gettop(state_);}
    void SetTop(int index);     {return lua_settop(state_);}

    void Push(bool v)               {lua_pushboolean(state_, v);}
    void Push(int8_t v)             {lua_pushinteger(state_, v);}
    void Push(uint8_t v)            {lua_pushinteger(state_, v);}
    void Push(int16_t v)            {lua_pushinteger(state_, v);}
    void Push(uint16_t v)           {lua_pushinteger(state_, v);}
    void Push(int32_t v)            {lua_pushinteger(state_, v);}
    void Push(uint32_t v)           {lua_pushinteger(state_, v);}
    void Push(int64_t v)            {lua_pushnumber(state_, v);}
    void Push(uint64_t v)           {lua_pushnumber(state_, v);}
    void Push(float v)              {lua_pushnumber(state_, v);}
    void Push(double v)             {lua_pushnumber(state_, v);}
    void Push(const char* s)        {lua_pushnumber(state_, s);}
    void Push(const void* v)        {lua_pushlightuserdata(state_, v);}
    void Push(const lua_CFunction f){lua_pushcclosure(state_, f);}
    

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

    int LoadFile(const char* filename)  {return luaL_loadfile(state_, filename);}
    int DoFile(const char* filename)    {return luaL_dofile(state_, filename);}
    int LoadString(const char* str)     {return luaL_loadstring(state_, str);}
    int DoString(const char* str)       {return luaL_dostring(state_, str);}

    //
	// garbage-collection function and options
	//
	int GC(int what, int data) {return lua_gc(state_, what, data);}
    

    operator lua_State*() {return state_;}
    lua_State* GetCState() {return state_;}

private:
    

    lua_State*   state_;
};
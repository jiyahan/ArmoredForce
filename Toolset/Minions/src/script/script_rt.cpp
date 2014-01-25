#include "script_rt.h"
#include "minion_script.h"
#include "msg_script.h"

lua_State*  ScriptRuntime::state_ = NULL;


bool ScriptRuntime::Init()
{
    state_ = luaL_newstate();
    luaL_openlibs(state_);
    InitMessageScript(state_);
    InitMinionScript(state_);
    return true;
}

void ScriptRuntime::Release()
{
    if (state_)
    {
        lua_close(state_);
        state_ = NULL;
    }
}

bool ScriptRuntime::DoFile(const char* filename)
{
    CHECK(state_ && filename);
    bool ok = (luaL_dofile(state_, filename) == 0);
    if (!ok)
    {
        LOG(ERROR) << lua_tostring(state_, -1);
    }
    return ok;
}

void ScriptRuntime::NewUserData(const char* meta, void* data)
{
    CHECK(meta && data);
    void* udata = lua_newuserdata(state_, sizeof(data));
    memcpy(udata, &data, sizeof(data));
    luaL_getmetatable(state_, meta);
    lua_setmetatable(state_, -2);
}

bool ScriptRuntime::Call(int params /*= 0*/, int results /*= LUA_MULTRET*/)
{
    bool ok = (lua_pcall(state_, params, results, 0) == 0);
    if (!ok)
    {
        LOG(ERROR) << lua_tostring(state_, -1);
        lua_pop(state_, 1);
    }
    return ok;
}

bool ScriptRuntime::Call(const char* func, const char* fmt, ...)
{
    CHECK(func && fmt);
    va_list ap;
    va_start(ap, fmt);
    return DoCall(func, fmt, ap);
}

int ScriptRuntime::PerformGC(bool full /*= false*/)
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

int ScriptRuntime::ParseParam(const char* fmt, va_list ap)
{
    int params = 0;
    for (; *fmt; ++fmt)
    {
        if (*fmt == '%')
        {
            ++fmt;
            switch(*fmt)
            {
            case '\0': 
                break;
            case 'b':
                {
                    int b = va_arg(ap, int);
                    lua_pushboolean(state_, b);
                    params++;
                }
                break;
            case 'c':
            case 'h':
            case 'i':
                {
                    int32_t n = va_arg(ap, int);
                    lua_pushinteger(state_, n);
                    params++;
                }
                break;
            case 'f':
            case 'd':
                {
                    double d = (double)va_arg(ap, double);
                    lua_pushnumber(state_, d);
                    params++;
                }
                break;
            case 'q':
                {
                    int64_t n = (int64_t)va_arg(ap, int64_t);
                    lua_pushnumber(state_, (lua_Number)n);
                    params++;
                }
                break;
            case 's':
                {
                    const char* s = (const char*)va_arg(ap, int);
                    lua_pushstring(state_, s);
                    params++;
                }
                break;
            }
        }
    }    
    return params;
}

bool ScriptRuntime::DoCall(const char* func, const char* fmt, va_list ap)
{
    CHECK(func && fmt);
    lua_getglobal(state_, func);
    int params = ParseParam(fmt, ap);
    va_end(ap);
    if (lua_pcall(state_, params, LUA_MULTRET, 0) != 0)
    {
        LOG(ERROR) << lua_tostring(state_, -1);
        lua_pop(state_, 1);
        return false;
    }
    return true;
}

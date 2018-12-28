#include "LuaUtil.h"
#include "KVSScreen_Lua.h"
#include "KVSStochasticRenderingCompositor_Lua.h"
extern "C" {


int luaopen_KVSScreen(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER(L, KVSScreen_Lua);
    LUA_SCRIPTCLASS_REGISTER(L, KVSStochasticRenderingCompositor_Lua);
    lua_newtable(L);
    lua_pushstring(L, "Screen");
    lua_pushcfunction(L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSScreen_Lua));
    lua_settable(L, -3);

    lua_pushstring(L, "StochasticRenderingCompositor");
    lua_pushcfunction(L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSStochasticRenderingCompositor_Lua));
    lua_settable(L, -3);
    return 1;
}

}

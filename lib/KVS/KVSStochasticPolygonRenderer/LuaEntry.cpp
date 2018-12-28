#include "LuaUtil.h"
#include "KVSStochasticPolygonRenderer_Lua.h"

extern "C" {


int luaopen_KVSStochasticPolygonRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSStochasticPolygonRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSStochasticPolygonRenderer_Lua ) );
    return 1;
}

}

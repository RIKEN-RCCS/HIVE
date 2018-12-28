#include "LuaUtil.h"
#include "KVSStochasticTetrahedraRenderer_Lua.h"

extern "C" {


int luaopen_KVSStochasticTetrahedraRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSStochasticTetrahedraRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSStochasticTetrahedraRenderer_Lua ) );
    return 1;
}

}

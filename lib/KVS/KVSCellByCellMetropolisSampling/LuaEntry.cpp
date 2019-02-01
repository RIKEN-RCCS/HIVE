#include "LuaUtil.h"
#include "KVSCellByCellMetropolisSampling_Lua.h"

extern "C" {

int luaopen_KVSCellByCellMetropolisSampling( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSCellByCellMetropolisSampling_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSCellByCellMetropolisSampling_Lua) );
    return 1;
}

}

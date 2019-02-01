#include "LuaUtil.h"
#include "KVSCellByCellUniformSampling_Lua.h"

extern "C" {

int luaopen_KVSCellByCellUniformSampling( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSCellByCellUniformSampling_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSCellByCellUniformSampling_Lua) );
    return 1;
}

}

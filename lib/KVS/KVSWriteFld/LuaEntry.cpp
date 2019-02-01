#include "LuaUtil.h"
#include "KVSWriteFld_Lua.h"

extern "C" {

int luaopen_KVSWriteFld( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSWriteFld_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSWriteFld_Lua) );
    return 1;
}

}

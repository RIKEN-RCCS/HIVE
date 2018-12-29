#include "LuaUtil.h"
#include "KVSPointGenerator_Lua.h"

extern "C" {


int luaopen_KVSPointGenerator( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSPointGenerator_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSPointGenerator_Lua) );
    return 1;
}

}

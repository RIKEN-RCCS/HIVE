#include "LuaUtil.h"
#include "KVSHydrogenVolumeData_Lua.h"

extern "C" {


int luaopen_KVSHydrogenVolumeData( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSHydrogenVolumeData_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSHydrogenVolumeData_Lua) );
    return 1;
}

}

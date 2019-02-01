#include "LuaUtil.h"
#include "KVSHAVSVolumeRenderer_Lua.h"

extern "C" {


int luaopen_KVSHAVSVolumeRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSHAVSVolumeRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSHAVSVolumeRenderer_Lua ) );
    return 1;
}

}

#include "LuaUtil.h"
#include "KVSParticleBasedRenderer_Lua.h"

extern "C" {


int luaopen_KVSParticleBasedRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSParticleBasedRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSParticleBasedRenderer_Lua ) );
    return 1;
}

}

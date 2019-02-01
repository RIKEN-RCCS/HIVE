#include "LuaUtil.h"
#include "KVSGLSLParticleBasedRenderer_Lua.h"

extern "C" {


int luaopen_KVSGLSLParticleBasedRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSGLSLParticleBasedRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSGLSLParticleBasedRenderer_Lua ) );
    return 1;
}

}

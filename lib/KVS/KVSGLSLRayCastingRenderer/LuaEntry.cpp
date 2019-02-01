#include "LuaUtil.h"
#include "KVSGLSLRayCastingRenderer_Lua.h"

extern "C" {


int luaopen_KVSGLSLRayCastingRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSGLSLRayCastingRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSGLSLRayCastingRenderer_Lua ) );
    return 1;
}

}

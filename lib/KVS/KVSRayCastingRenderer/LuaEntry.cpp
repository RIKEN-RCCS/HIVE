#include "LuaUtil.h"
#include "KVSRayCastingRenderer_Lua.h"

extern "C" {


int luaopen_KVSRayCastingRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSRayCastingRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSRayCastingRenderer_Lua ) );
    return 1;
}

}

#include "LuaUtil.h"
#include "KVSLineRenderer_Lua.h"

extern "C" {


int luaopen_KVSLineRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSLineRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSLineRenderer_Lua ) );
    return 1;
}

}

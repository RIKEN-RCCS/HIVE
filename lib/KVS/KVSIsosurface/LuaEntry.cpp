#include "LuaUtil.h"
#include "KVSIsosurface_Lua.h"

extern "C" {

int luaopen_KVSIsosurface( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSIsosurface_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSIsosurface_Lua) );
    return 1;
}

}

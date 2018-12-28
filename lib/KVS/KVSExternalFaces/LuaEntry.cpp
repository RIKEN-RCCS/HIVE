#include "LuaUtil.h"
#include "KVSExternalFaces_Lua.h"

extern "C" {

int luaopen_KVSExternalFaces( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSExternalFaces_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSExternalFaces_Lua) );
    return 1;
}

}

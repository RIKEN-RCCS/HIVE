#include "LuaUtil.h"
#include "KVSRenderObject_Lua.h"

extern "C" {

int luaopen_KVSRenderObject(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSRenderObject_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSRenderObject_Lua) );
    return 1;
}

}

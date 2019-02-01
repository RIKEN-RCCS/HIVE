#include "LuaUtil.h"
#include "KVSGenericObject_Lua.h"

extern "C" {


int luaopen_KVSGenericObject(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSGenericObject_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSGenericObject_Lua) );
    return 1;
}

}

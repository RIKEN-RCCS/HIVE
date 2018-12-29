#include "LuaUtil.h"
#include "KVSXform_Lua.h"

extern "C" {

int luaopen_KVSXform(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSXform_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSXform_Lua) );
    return 1;
}

}

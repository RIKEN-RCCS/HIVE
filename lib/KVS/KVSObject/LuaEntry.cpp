#include "LuaUtil.h"
#include "KVSObject_Lua.h"

extern "C" {


int luaopen_KVSObject(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSObject_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSObject_Lua) );
    return 1;
}

}

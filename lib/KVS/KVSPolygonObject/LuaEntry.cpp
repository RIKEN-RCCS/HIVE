#include "LuaUtil.h"
#include "KVSPolygonObject_Lua.h"

extern "C" {


int luaopen_KVSPolygonObject(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSPolygonObject_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSPolygonObject_Lua) );
    return 1;
}

}

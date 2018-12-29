#include "LuaUtil.h"
#include "KVSPolygonImporter_Lua.h"

extern "C" {


int luaopen_KVSPolygonImporter( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSPolygonImporter_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSPolygonImporter_Lua) );
    return 1;
}

}

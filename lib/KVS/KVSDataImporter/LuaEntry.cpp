#include "LuaUtil.h"
#include "KVSDataImporter_Lua.h"

extern "C" {


int luaopen_KVSDataImporter( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSDataImporter_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSDataImporter_Lua) );
    return 1;
}

}

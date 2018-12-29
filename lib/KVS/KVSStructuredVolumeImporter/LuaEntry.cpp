#include "LuaUtil.h"
#include "KVSStructuredVolumeImporter_Lua.h"

extern "C" {


int luaopen_KVSStructuredVolumeImporter( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSStructuredVolumeImporter_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSStructuredVolumeImporter_Lua) );
    return 1;
}

}

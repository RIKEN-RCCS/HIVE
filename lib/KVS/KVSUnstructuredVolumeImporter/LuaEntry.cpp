#include "LuaUtil.h"
#include "KVSUnstructuredVolumeImporter_Lua.h"

extern "C" {


int luaopen_KVSUnstructuredVolumeImporter( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSUnstructuredVolumeImporter_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSUnstructuredVolumeImporter_Lua) );
    return 1;
}

}

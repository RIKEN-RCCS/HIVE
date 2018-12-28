#include "LuaUtil.h"
#include "KVSTornadoVolumeData_Lua.h"

extern "C" {


int luaopen_KVSTornadoVolumeData( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSTornadoVolumeData_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSTornadoVolumeData_Lua) );
    return 1;
}

}

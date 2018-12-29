#include "LuaUtil.h"
#include "KVSUniColor_Lua.h"

extern "C" {

int luaopen_KVSUniColor( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSUniColor_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSUniColor_Lua) );
    return 1;
}

}

#include "LuaUtil.h"
#include "KVSStreamline_Lua.h"

extern "C" {


int luaopen_KVSStreamline( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSStreamline_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSStreamline_Lua) );
    return 1;
}

}

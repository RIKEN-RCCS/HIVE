#include "LuaUtil.h"
#include "KVSSphereGlyph_Lua.h"

extern "C" {


int luaopen_KVSSphereGlyph( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSSphereGlyph_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION(KVSSphereGlyph_Lua) );
    return 1;
}

}

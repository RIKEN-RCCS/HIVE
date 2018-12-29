#include "LuaUtil.h"
#include "KVSStylizedLineRenderer_Lua.h"

extern "C" {


int luaopen_KVSStylizedLineRenderer( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSStylizedLineRenderer_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSStylizedLineRenderer_Lua ) );
    return 1;
}

}

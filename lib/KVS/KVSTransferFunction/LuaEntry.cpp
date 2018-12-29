#include "LuaUtil.h"
#include "KVSTransferFunction_Lua.h"

extern "C" {


int luaopen_KVSTransferFunction( lua_State* L )
{
    LUA_SCRIPTCLASS_REGISTER( L, KVSTransferFunction_Lua );
    lua_pushcfunction( L, LUA_SCRIPTCLASS_NEW_FUNCTION( KVSTransferFunction_Lua ) );
    return 1;
}

}

#include "LuaUtil.h"
#include "BufferExtraData_Lua.h"
#include "PdmLoader_Lua.h"

extern "C" {


int luaopen_PdmLoader(lua_State* L)
{
    LUA_SCRIPTCLASS_REGISTER(L, PDMLoader_Lua);
    lua_pushcfunction(L, LUA_SCRIPTCLASS_NEW_FUNCTION(PDMLoader_Lua));
    return 1;
}

}


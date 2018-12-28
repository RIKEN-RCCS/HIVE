/**
 * @file KVSScreen_Lua.h
 * Screen Luaラッパー
 */
#ifndef _KVSSCREEN_LUA_H_
#define _KVSSCREEN_LUA_H_

#include "LuaUtil.h"
#include "KVSScreen.h"
#include "BufferImageData_Lua.h"
/**
 * Screen Luaラッパー
 */
class KVSScreen_Lua : public KVSScreen
{
public:
    KVSScreen_Lua() {}
    ~KVSScreen_Lua() {}

    BufferImageData_Lua* Image() {
        return new BufferImageData_Lua( KVSScreen::Image() );
    }

    LUA_SCRIPTCLASS_BEGIN( KVSScreen_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( int, Width )
    LUA_SCRIPTCLASS_METHOD_ARG0( int, Height )
    LUA_SCRIPTCLASS_METHOD_MEASURE_CALC_ARG0( "KVSScreen", bool, Render )
    LUA_SCRIPTCLASS_METHOD_ARG0( BufferImageData_Lua*, Image )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, Register, void*, void* )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Clear )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, SetScreenSize, int, int )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSScreen_Lua );

#endif //_KVSSCREEN_LUA_H_

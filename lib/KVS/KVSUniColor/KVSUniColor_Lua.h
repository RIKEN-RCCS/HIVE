/**
 * @file KVSUniColor_Lua.h
 * KVSUniColor Luaラッパー
 */
#ifndef _KVSUNICOLOR_LUA_H_
#define _KVSUNICOLOR_LUA_H_

#include "LuaUtil.h"
#include "KVSUniColor.h"

/**
 * KVSUniColor Luaラッパー
 */
class KVSUniColor_Lua : public KVSUniColor
{
public:
    KVSUniColor_Lua() {}
    ~KVSUniColor_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSUniColor_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG4( bool, SetColor, int, int, int, int )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetGeometryObject, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSUniColor_Lua );

#endif //_KVSUNICOLOR_LUA_H_

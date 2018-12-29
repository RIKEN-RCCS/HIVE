/**
 * @file KVSStreamline_Lua.h
 * KVSStreamline Luaラッパー
 */
#ifndef _KVSSTREAMLINE_LUA_H_
#define _KVSSTREAMLINE_LUA_H_

#include "LuaUtil.h"
#include "KVSStreamline.h"

/**
 * KVSStreamline Luaラッパー
 */
class KVSStreamline_Lua : public KVSStreamline
{
public:
    KVSStreamline_Lua() {}
    ~KVSStreamline_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSStreamline_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetMinCoord, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetMaxCoord, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetDelta, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Exec )
    LUA_SCRIPTCLASS_END()
        };
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStreamline_Lua );

#endif //_KVSSTREAMLINE_LUA_H_

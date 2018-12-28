/**
 * @file KVSRayCastingRenderer_Lua.h
 * KVSRayCastingRenderer Luaラッパー
 */
#ifndef _KVSRAYCASTINGRENDERER_LUA_H_
#define _KVSRAYCASTINGRENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSRayCastingRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSRayCastingRenderer_Lua : public KVSRayCastingRenderer
{
public:
    KVSRayCastingRenderer_Lua() {}
    ~KVSRayCastingRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSRayCastingRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetOpaqueValue, float )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetSamplingStep, float )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSRayCastingRenderer_Lua );

#endif //_KVSRAYCASTINGRENDERER_LUA_H_

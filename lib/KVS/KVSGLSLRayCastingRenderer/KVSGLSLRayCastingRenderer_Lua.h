/**
 * @file KVSGLSLRayCastingRenderer_Lua.h
 * KVSGLSLRayCastingRenderer Luaラッパー
 */
#ifndef _KVSGLSLRAYCASTINGRENDERER_LUA_H_
#define _KVSGLSLRAYCASTINGRENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSGLSLRayCastingRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSGLSLRayCastingRenderer_Lua : public KVSGLSLRayCastingRenderer
{
public:
    KVSGLSLRayCastingRenderer_Lua() {}
    ~KVSGLSLRayCastingRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSGLSLRayCastingRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSGLSLRayCastingRenderer_Lua );

#endif //_KVSGLSLRAYCASTINGRENDERER_LUA_H_

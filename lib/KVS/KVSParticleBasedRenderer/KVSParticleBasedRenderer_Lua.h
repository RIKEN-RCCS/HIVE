/**
 * @file KVSParticleBasedRenderer_Lua.h
 * KVSParticleBasedRenderer Luaラッパー
 */
#ifndef _KVSPARTICLEBASEDRENDERER_LUA_H_
#define _KVSPARTICLEBASEDRENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSParticleBasedRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSParticleBasedRenderer_Lua : public KVSParticleBasedRenderer
{
public:
    KVSParticleBasedRenderer_Lua() {}
    ~KVSParticleBasedRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSParticleBasedRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetSubpixelLevel, int )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableShading, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSParticleBasedRenderer_Lua );

#endif //_KVSPARTICLEBASEDRENDERER_LUA_H_

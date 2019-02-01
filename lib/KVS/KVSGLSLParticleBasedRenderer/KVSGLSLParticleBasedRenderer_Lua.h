/**
 * @file KVSGLSLParticleBasedRenderer_Lua.h
 * KVSGLSLParticleBasedRenderer Luaラッパー
 */
#ifndef _KVSGLSLPARTICLEBASEDRENDERER_LUA_H_
#define _KVSGLSLPARTICLEBASEDRENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSGLSLParticleBasedRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSGLSLParticleBasedRenderer_Lua : public KVSGLSLParticleBasedRenderer
{
public:
    KVSGLSLParticleBasedRenderer_Lua() {}
    ~KVSGLSLParticleBasedRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSGLSLParticleBasedRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRepetitionLevel, int )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableLODControl, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableShading, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSGLSLParticleBasedRenderer_Lua );

#endif //_KVSGLSLPARTICLEBASEDRENDERER_LUA_H_

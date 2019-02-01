/**
 * @file KVSHAVSVolumeRenderer_Lua.h
 * KVSHAVSVolumeRenderer Luaラッパー
 */
#ifndef _KVSHAVSVOLUMERENDERER_LUA_H_
#define _KVSHAVSVOLUMERENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSHAVSVolumeRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSHAVSVolumeRenderer_Lua : public KVSHAVSVolumeRenderer
{
public:
    KVSHAVSVolumeRenderer_Lua() {}
    ~KVSHAVSVolumeRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSHAVSVolumeRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetKBufferSize, int )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSHAVSVolumeRenderer_Lua );

#endif //_KVSHAVSVOLUMERENDERER_LUA_H_

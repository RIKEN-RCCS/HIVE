/**
 * @file KVSLineRenderer_Lua.h
 * KVSLineRenderer Luaラッパー
 */
#ifndef _KVSLINERENDERER_LUA_H_
#define _KVSLINERENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSLineRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSLineRenderer_Lua : public KVSLineRenderer
{
public:
    KVSLineRenderer_Lua() {}
    ~KVSLineRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSLineRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetEnabledShading, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSLineRenderer_Lua );

#endif //_KVSLINERENDERER_LUA_H_

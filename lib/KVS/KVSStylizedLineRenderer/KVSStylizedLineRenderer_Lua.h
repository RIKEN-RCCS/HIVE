/**
 * @file KVSStylizedLineRenderer_Lua.h
 * KVSStylizedLineRenderer Luaラッパー
 */
#ifndef _KVSSTYLIZEDLINERENDERER_LUA_H_
#define _KVSSTYLIZEDLINERENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSStylizedLineRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSStylizedLineRenderer_Lua : public KVSStylizedLineRenderer
{
public:
    KVSStylizedLineRenderer_Lua() {}
    ~KVSStylizedLineRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSStylizedLineRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
	LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableShading, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStylizedLineRenderer_Lua );

#endif //_KVSSTYLIZEDLINERENDERER_LUA_H_

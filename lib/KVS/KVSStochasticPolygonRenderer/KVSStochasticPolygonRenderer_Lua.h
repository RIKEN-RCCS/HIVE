/**
 * @file KVSStochasticPolygonRenderer_Lua.h
 * KVSStochasticPolygonRenderer Luaラッパー
 */
#ifndef _KVSSTOCHASTICPOLYGONRARENDERER_LUA_H_
#define _KVSSTOCHASTICPOLYGONRARENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSStochasticPolygonRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSStochasticPolygonRenderer_Lua : public KVSStochasticPolygonRenderer
{
public:
    KVSStochasticPolygonRenderer_Lua() {}
    ~KVSStochasticPolygonRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSStochasticPolygonRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableShading, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStochasticPolygonRenderer_Lua );

#endif //_KVSSTOCHASTICPOLYGONRARENDERER_LUA_H_

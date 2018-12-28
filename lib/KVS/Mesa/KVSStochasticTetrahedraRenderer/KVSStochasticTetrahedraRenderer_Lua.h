/**
 * @file KVSStochasticTetrahedraRenderer_Lua.h
 * KVSStochasticTetrahedraRenderer Luaラッパー
 */
#ifndef _KVSSTOCHASTICTETRAHEDRARENDERER_LUA_H_
#define _KVSSTOCHASTICTETRAHEDRARENDERER_LUA_H_

#include "LuaUtil.h"
#include "KVSStochasticTetrahedraRenderer.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSStochasticTetrahedraRenderer_Lua : public KVSStochasticTetrahedraRenderer
{
public:
    KVSStochasticTetrahedraRenderer_Lua() {}
    ~KVSStochasticTetrahedraRenderer_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSStochasticTetrahedraRenderer_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableShading, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStochasticTetrahedraRenderer_Lua );

#endif //_KVSSTOCHASTICTETRAHEDRARENDERER_LUA_H_

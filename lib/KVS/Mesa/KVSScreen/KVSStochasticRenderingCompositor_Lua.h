/**
 * @file KVSStochasticRenderingCompositor_Lua.h
 * Screen Luaラッパー
 */
#ifndef _KVSSCREENCOMPOSITOR_LUA_H_
#define _KVSSCREENCOMPOSITOR_LUA_H_

#include "LuaUtil.h"
#include "KVSStochasticRenderingCompositor.h"
#include "BufferImageData_Lua.h"
/**
 * Screen Luaラッパー
 */
class KVSStochasticRenderingCompositor_Lua : public KVSStochasticRenderingCompositor
{
public:
    KVSStochasticRenderingCompositor_Lua() {}
    ~KVSStochasticRenderingCompositor_Lua() {}

    BufferImageData_Lua* Image() {
        return new BufferImageData_Lua( KVSStochasticRenderingCompositor::Image() );
    }

    LUA_SCRIPTCLASS_BEGIN( KVSStochasticRenderingCompositor_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( int,Width)
    LUA_SCRIPTCLASS_METHOD_ARG0( int,Height)
    LUA_SCRIPTCLASS_METHOD_MEASURE_CALC_ARG0( "KVSStochasticRenderingCompositor", bool, Composite )
    LUA_SCRIPTCLASS_METHOD_ARG0( BufferImageData_Lua*, Image )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, Register, void*, void* )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Clear )
	LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRepetitionLevel, int )
	LUA_SCRIPTCLASS_METHOD_ARG1( bool, EnableLODControl, bool )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, SetScreenSize, int, int )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStochasticRenderingCompositor_Lua );

#endif //_KVSSCREENCOMPOSITOR_LUA_H_

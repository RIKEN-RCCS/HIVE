/**
 * @file KVSRenderObject_Lua.h
 * KVSRenderObject Luaラッパー
 */
#ifndef _KVSRENDEROBJECT_LUA_H_
#define _KVSRENDEROBJECT_LUA_H_

#include "LuaUtil.h"
#include "KVSRenderObject.h"
/**
 * KVSRenderObject Luaラッパー
 */
class KVSRenderObject_Lua : public KVSRenderObject
{
public:
    KVSRenderObject_Lua() {}
    ~KVSRenderObject_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSRenderObject_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Release )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRenderer, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShaderFlag, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShadingFlag, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShowFlag, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetXform, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSRenderObject_Lua );

#endif //_KVSRENDEROBJECT_LUA_H_

/**
 * @file KVSGenericObject_Lua.h
 * Object Luaラッパー
 */
#ifndef _KVSGENERICOBJECT_LUA_H_
#define _KVSGENERICOBJECT_LUA_H_

#include "LuaUtil.h"
#include "KVSGenericObject.h"
/**
 * Object Luaラッパー
 */
class KVSGenericObject_Lua : public KVSGenericObject
{
public:
    KVSGenericObject_Lua() {}
    ~KVSGenericObject_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSGenericObject_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetTranslate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetRotate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetScale, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG4( bool, SetColor, float, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Release )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShowFlag, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShadingFlag, bool )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetGPUFlag, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSGenericObject_Lua );

#endif //_KVSGENERICOBJECT_LUA_H_

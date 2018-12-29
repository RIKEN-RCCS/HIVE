/**
 * @file KVSObject_Lua.h
 * Object Luaラッパー
 */
#ifndef _KVSOBJECT_LUA_H_
#define _KVSOBJECT_LUA_H_

#include "LuaUtil.h"
#include "KVSObject.h"
/**
 * Object Luaラッパー
 */
class KVSObject_Lua : public KVSObject
{
public:
    KVSObject_Lua() {}
    ~KVSObject_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSObject_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetTranslate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetRotate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetScale, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRenderer, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Release )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShowFlag, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSObject_Lua );

#endif //_KVSOBJECT_LUA_H_

/**
 * @file KVSPolygonObject_Lua.h
 * Object Luaラッパー
 */
#ifndef _KVSPOLYGONOBJECT_LUA_H_
#define _KVSPOLYGONOBJECT_LUA_H_

#include "LuaUtil.h"
#include "KVSPolygonObject.h"
/**
 * Object Luaラッパー
 */
class KVSPolygonObject_Lua : public KVSPolygonObject
{
public:
    KVSPolygonObject_Lua() {}
    ~KVSPolygonObject_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSPolygonObject_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetTranslate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetRotate, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetScale, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG4( bool,SetColor, float, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Renderer )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, PolygonObject )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRenderer, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetPolygonObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Release )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetShowFlag, bool )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSPolygonObject_Lua );

#endif //_KVSPOLYGONOBJECT_LUA_H_

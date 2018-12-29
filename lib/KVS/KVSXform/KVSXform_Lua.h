/**
 * @file KVSXform_Lua.h
 * KVSXform Luaラッパー
 */
#ifndef _KVSXFORM_LUA_H_
#define _KVSXFORM_LUA_H_

#include "LuaUtil.h"
#include "KVSXform.h"
/**
 * KVSXform Luaラッパー
 */
class KVSXform_Lua : public KVSXform
{
public:
    KVSXform_Lua() {}
    ~KVSXform_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSXform_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetRotation, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetScaling, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool,SetTranslation, float, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Xform )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSXform_Lua );

#endif //_KVSXFORM_LUA_H_

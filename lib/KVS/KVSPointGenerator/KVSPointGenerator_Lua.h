/**
 * @file KVSPointGenerator_Lua.h
 * KVSPointGenerator Luaラッパー
 */
#ifndef _KVSPOINTGENERATOR_LUA_H_
#define _KVSPOINTGENERATOR_LUA_H_

#include "LuaUtil.h"
#include "KVSPointGenerator.h"

/**
 * KVSPointGenerator Luaラッパー
 */
class KVSPointGenerator_Lua : public KVSPointGenerator
{
public:
    KVSPointGenerator_Lua() {}
    ~KVSPointGenerator_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSPointGenerator_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetMinCoord, int, int, int )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetMaxCoord, int, int, int )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Generate )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSPointGenerator_Lua );

#endif //_KVSPOINTGENERATOR_LUA_H_

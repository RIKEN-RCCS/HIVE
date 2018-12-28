/**
 * @file KVSExternalFaces_Lua.h
 * KVSExternalFaces Luaラッパー
 */
#ifndef _KVSEXTERNALFACES_LUA_H_
#define _KVSEXTERNALFACES_LUA_H_

#include "LuaUtil.h"
#include "KVSExternalFaces.h"

/**
 * KVSExternalFaces Luaラッパー
 */
class KVSExternalFaces_Lua : public KVSExternalFaces
{
public:
    KVSExternalFaces_Lua() {}
    ~KVSExternalFaces_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSExternalFaces_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSExternalFaces_Lua );

#endif //_KVSEXTERNALFACES_LUA_H_

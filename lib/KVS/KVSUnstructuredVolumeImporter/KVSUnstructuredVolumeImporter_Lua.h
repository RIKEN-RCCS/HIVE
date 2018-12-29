/**
 * @file KVSUnstructuredVolumeImporter_Lua.h
 * KVSUnstructuredVolumeImporter Luaラッパー
 */
#ifndef _KVSUNSTRUCTUREDVOLUMEIMPORTER_LUA_H_
#define _KVSUNSTRUCTUREDVOLUMEIMPORTER_LUA_H_

#include "LuaUtil.h"
#include "KVSUnstructuredVolumeImporter.h"
#include "BufferImageData_Lua.h"

/**
 * KVSUnstructuredVolumeImporter Luaラッパー
 */
class KVSUnstructuredVolumeImporter_Lua : public KVSUnstructuredVolumeImporter
{
public:
    KVSUnstructuredVolumeImporter_Lua() {}
    ~KVSUnstructuredVolumeImporter_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSUnstructuredVolumeImporter_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool,SetFile, std::string )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG0( float, MinValue )
    LUA_SCRIPTCLASS_METHOD_ARG0( float, MaxValue )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSUnstructuredVolumeImporter_Lua );

#endif //_KVSUNSTRUCTUREDVOLUMEIMPORTER_LUA_H_

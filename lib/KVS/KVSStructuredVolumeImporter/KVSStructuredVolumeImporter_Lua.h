/**
 * @file KVSStructuredVolumeImporter_Lua.h
 * KVSStructuredVolumeImporter Luaラッパー
 */
#ifndef _KVSSTRUCTUREDVOLUMEIMPORTER_LUA_H_
#define _KVSSTRUCTUREDVOLUMEIMPORTER_LUA_H_

#include "LuaUtil.h"
#include "KVSStructuredVolumeImporter.h"
#include "BufferImageData_Lua.h"

/**
 * KVSStructuredVolumeImporter Luaラッパー
 */
class KVSStructuredVolumeImporter_Lua : public KVSStructuredVolumeImporter
{
public:
    KVSStructuredVolumeImporter_Lua() {}
    ~KVSStructuredVolumeImporter_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSStructuredVolumeImporter_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool,SetFile, std::string )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSStructuredVolumeImporter_Lua );

#endif //_KVSSTRUCTUREDVOLUMEIMPORTER_LUA_H_

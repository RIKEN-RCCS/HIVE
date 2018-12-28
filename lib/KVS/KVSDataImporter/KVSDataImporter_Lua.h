/**
 * @file KVSDataImporter_Lua.h
 * KVSDataImporter Luaラッパー
 */
#ifndef _KVSDATAIMPORTER_LUA_H_
#define _KVSDATAIMPORTER_LUA_H_

#include "LuaUtil.h"
#include "KVSDataImporter.h"
#include "BufferImageData_Lua.h"

/**
 * KVSDataImporter Luaラッパー
 */
class KVSDataImporter_Lua : public KVSDataImporter
{
public:
    KVSDataImporter_Lua() {}
    ~KVSDataImporter_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSDataImporter_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool,SetFile, std::string )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSDataImporter_Lua );

#endif //_KVSDATAIMPORTER_LUA_H_

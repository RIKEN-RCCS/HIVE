/**
 * @file KVSPolygonImporter_Lua.h
 * KVSPolygonImporter Luaラッパー
 */
#ifndef _KVSPOLYGONIMPORTER_LUA_H_
#define _KVSPOLYGONIMPORTER_LUA_H_

#include "LuaUtil.h"
#include "KVSPolygonImporter.h"
#include "BufferImageData_Lua.h"

/**
 * KVSPolygonImporter Luaラッパー
 */
class KVSPolygonImporter_Lua : public KVSPolygonImporter
{
public:
    KVSPolygonImporter_Lua() {}
    ~KVSPolygonImporter_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSPolygonImporter_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool,SetFile, std::string )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSPolygonImporter_Lua );

#endif //_KVSPOLYGONIMPORTER_LUA_H_

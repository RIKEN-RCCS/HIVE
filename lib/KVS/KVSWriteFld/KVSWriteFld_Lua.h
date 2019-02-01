/**
 * @file KVSWriteFld_Lua.h
 * KVSWriteFld Lua wrapper
 */
#ifndef _KVSWRITEFLD_LUA_H_
#define _KVSWRITEFLD_LUA_H_

#include "LuaUtil.h"
#include "KVSWriteFld.h"

/**
 * KVSWriteFld Lua wrapper
 */
class KVSWriteFld_Lua : public KVSWriteFld
{
public:
    KVSWriteFld_Lua() {}
    ~KVSWriteFld_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSWriteFld_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )	
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetOutputFilePath, std::string )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSWriteFld_Lua );

#endif //_KVSWRITEFLD_LUA_H_

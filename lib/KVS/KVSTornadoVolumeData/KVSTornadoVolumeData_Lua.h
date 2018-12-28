/**
 * @file KVSTornadoVolumeData_Lua.h
 * KVSTornadoVolumeData Luaラッパー
 */
#ifndef _KVSTORNADOVOLUMEDATA_LUA_H_
#define _KVSTORNADOVOLUMEDATA_LUA_H_

#include "LuaUtil.h"
#include "KVSTornadoVolumeData.h"

/**
 * KVSTornadoVolumeData Luaラッパー
 */
class KVSTornadoVolumeData_Lua : public KVSTornadoVolumeData
{
public:
    KVSTornadoVolumeData_Lua() {}
    ~KVSTornadoVolumeData_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSTornadoVolumeData_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTime, float )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetResolution, int, int, int )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*,Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSTornadoVolumeData_Lua );

#endif //_KVSTORNADOVOLUMEDATA_LUA_H_

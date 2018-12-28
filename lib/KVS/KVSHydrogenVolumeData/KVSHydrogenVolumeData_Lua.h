/**
 * @file KVSHydrogenVolumeData_Lua.h
 * KVSHydrogenVolumeData Luaラッパー
 */
#ifndef _KVSHYDROGENVOLUMEDATA_LUA_H_
#define _KVSHYDROGENVOLUMEDATA_LUA_H_

#include "LuaUtil.h"
#include "KVSHydrogenVolumeData.h"

/**
 * KVSHydrogenVolumeData Luaラッパー
 */
class KVSHydrogenVolumeData_Lua : public KVSHydrogenVolumeData
{
public:
    KVSHydrogenVolumeData_Lua() {}
    ~KVSHydrogenVolumeData_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSHydrogenVolumeData_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG3( bool, SetResolution, int, int, int )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSHydrogenVolumeData_Lua );

#endif //_KVSHYDROGENVOLUMEDATA_LUA_H_

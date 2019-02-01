/**
 * @file KVSCellByCellUniformSampling_Lua.h
 * KVSCellByCellUniformSampling Luaラッパー
 */
#ifndef _KVSCELLBYCELLUNIFORMSAMPLING_LUA_H_
#define _KVSCELLBYCELLUNIFORMSAMPLING_LUA_H_

#include "LuaUtil.h"
#include "KVSCellByCellUniformSampling.h"

/**
 * KVSCellByCellUniformSampling Luaラッパー
 */
class KVSCellByCellUniformSampling_Lua : public KVSCellByCellUniformSampling
{
public:
    KVSCellByCellUniformSampling_Lua() {}
    ~KVSCellByCellUniformSampling_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSCellByCellUniformSampling_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Execute )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRepetitionLevel, int )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetSamplingStep, float )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, SetMinMaxValues, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSCellByCellUniformSampling_Lua );

#endif //_KVSCELLBYCELLUNIFORMSAMPLING

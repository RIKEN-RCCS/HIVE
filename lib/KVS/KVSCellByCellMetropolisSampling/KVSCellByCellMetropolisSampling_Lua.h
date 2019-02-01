/**
 * @file KVSCellByCellMetropolisSampling_Lua.h
 * KVSCellByCellMetropolisSampling Luaラッパー
 */
#ifndef _KVSCELLBYCELLMETROPOLISSAMPLING_LUA_H_
#define _KVSCELLBYCELLMETROPOLISSAMPLING_LUA_H_

#include "LuaUtil.h"
#include "KVSCellByCellMetropolisSampling.h"

/**
 * KVSCellByCellMetropolisSampling Luaラッパー
 */
class KVSCellByCellMetropolisSampling_Lua : public KVSCellByCellMetropolisSampling
{
public:
    KVSCellByCellMetropolisSampling_Lua() {}
    ~KVSCellByCellMetropolisSampling_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSCellByCellMetropolisSampling_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG0( bool, Execute )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetRepetitionLevel, int )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetSamplingStep, float )
    LUA_SCRIPTCLASS_METHOD_ARG2( bool, SetMinMaxValues, float, float )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSCellByCellMetropolisSampling_Lua );

#endif //_KVSCELLBYCELLMETROPOLISSAMPLING_LUA_H_

/**
 * @file KVSIsosurface_Lua.h
 * KVSIsosurface Lua wrapper
 */
#ifndef _KVSISOSURFACE_LUA_H_
#define _KVSISOSURFACE_LUA_H_

#include "LuaUtil.h"
#include "KVSIsosurface.h"

/**
 * KVSIsosurface Lua wrapper
 */
class KVSIsosurface_Lua : public KVSIsosurface
{
public:
    KVSIsosurface_Lua() {}
    ~KVSIsosurface_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSIsosurface_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, Object )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetTransferFunction, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetVolumeObject, void* )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetIsolevel, float )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSIsosurface_Lua );

#endif //_KVSISOSURFACE_LUA_H_

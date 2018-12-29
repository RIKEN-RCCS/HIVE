/**
 * @file KVSTransferFunction_Lua.h
 * KVSTransferFunction Luaラッパー
 */
#ifndef _KVSTRANSFERFUNCTION_LUA_H_
#define _KVSTRANSFERFUNCTION_LUA_H_

#include "LuaUtil.h"
#include "KVSTransferFunction.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSTransferFunction_Lua : public KVSTransferFunction
{
 public:
    KVSTransferFunction_Lua() {}
    ~KVSTransferFunction_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSTransferFunction_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*, TransferFunction )
    LUA_SCRIPTCLASS_METHOD_ARG1( bool, SetFile, std::string )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSTransferFunction_Lua );

#endif //_KVSTRANSFERFUNCTION_LUA_H_

/**
 * @file STLLoader_Lua.h
 * STLLoader Luaラッパー
 */
#ifndef _STLLOADER_LUA_H_
#define _STLLOADER_LUA_H_


#include "LuaUtil.h"
#include "Buffer.h"
#include "BufferMeshData.h"
#include "StlLoader.h"
#include "BufferMeshData_Lua.h"
/**
 * STLLoader Luaラッパー
 */
class STLLoader_Lua : public STLLoader
{
public:
    STLLoader_Lua(){}
    ~STLLoader_Lua(){};

    bool Load(const char* filename, bool swap_endian=false){
        return STLLoader::Load(filename, swap_endian);
    }

    BufferMeshData_Lua* MeshData() {
        RefPtr<BufferMeshData> mesh = STLLoader::MeshData();
        return BufferMeshData_Lua::CreateInstance(mesh);
    }

    LUA_SCRIPTCLASS_BEGIN(STLLoader_Lua)
    LUA_SCRIPTCLASS_METHOD_MEASURE_CALC_ARG2("STLLoader",bool,Load,const char*,bool)
    LUA_SCRIPTCLASS_METHOD_ARG0(BufferMeshData_Lua*, MeshData)
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH(STLLoader_Lua);

#endif //_STLLOADER_LUA_H_


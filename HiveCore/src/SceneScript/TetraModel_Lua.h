/**
 * @file TetraModel_Lua.h
 * TetraModel Luaラッパー
 */
#ifndef _TETRAMODEL_LUA_H_
#define _TETRAMODEL_LUA_H_


#include "LuaUtil.h"
#include "../RenderObject/TetraModel.h"
#include "BufferTetraData_Lua.h"
#include "RenderObject_Lua.h"
/**
 * TetraModel Luaラッパー
 */
class TetraModel_Lua : public TetraModel
{
public:
    TetraModel_Lua(){}
    ~TetraModel_Lua(){}

    bool Create(BufferTetraData_Lua *tetra) {
        return TetraModel::Create(tetra);
    }

    // RenderObject interface implementation
    IMPLEMENTATION_RENDEROBJECT_LUA()

    LUA_SCRIPTCLASS_BEGIN(TetraModel_Lua)
    LUA_SCRIPTCLASS_METHOD_ARG1(bool, SetShader, const std::string&)
    LUA_SCRIPTCLASS_METHOD_ARG0(std::string, GetShader)
    LUA_SCRIPTCLASS_METHOD_ARG1(bool, Create, BufferTetraData_Lua*)
    
    // RenderObject interface
    DECLARE_RENDEROBJECT_LUA_METHOD()
    LUA_SCRIPTCLASS_END();
};
LUA_SCRIPTCLASS_CAST_AND_PUSH(TetraModel_Lua);


#endif //_TETRAMODEL_LUA_H_

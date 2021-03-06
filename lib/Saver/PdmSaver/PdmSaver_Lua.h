/**
 * @file PDMSaver_Lua.h
 * PDMSaver Luaラッパー
 */
#ifndef _PDMSAVER_LUA_H_
#define _PDMSAVER_LUA_H_

#include "LuaUtil.h"
#include "PdmSaver.h"
#include "BufferPointData_Lua.h"
/**
 * PDMSaver Luaラッパー
 */
class PDMSaver_Lua : public PDMSaver
{
public:
    PDMSaver_Lua() {}
    ~PDMSaver_Lua() {}

    bool Save(const char* filename) {
        return PDMSaver::Save(filename);
    }

    bool SetPointData(BufferPointData_Lua* p) {
        PDMSaver::SetPointData(p);
        return true;
    }

    LUA_SCRIPTCLASS_BEGIN(PDMSaver_Lua)
    LUA_SCRIPTCLASS_METHOD_MEASURE_CALC_ARG1("PDMSaver",bool,Save,const char*)
    LUA_SCRIPTCLASS_METHOD_ARG1(bool,SetPointData,BufferPointData_Lua*)
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH(PDMSaver_Lua);

#endif //_PDMSAVER_LUA_H_


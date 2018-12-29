/**
 * @file KVSSphereGlyph_Lua.h
 * KVSSphereGlyph Luaラッパー
 */
#ifndef _KVSSPHEREGLYPH_LUA_H_
#define _KVSSPHEREGLYPH_LUA_H_

#include "LuaUtil.h"
#include "KVSSphereGlyph.h"
#include "BufferImageData_Lua.h"

/**
 * Luaラッパー
 */
class KVSSphereGlyph_Lua : public KVSSphereGlyph
{
public:
    KVSSphereGlyph_Lua() {}
    ~KVSSphereGlyph_Lua() {}

    LUA_SCRIPTCLASS_BEGIN( KVSSphereGlyph_Lua )
    LUA_SCRIPTCLASS_METHOD_ARG0( const char*,Renderer )
    LUA_SCRIPTCLASS_END()
};
LUA_SCRIPTCLASS_CAST_AND_PUSH( KVSSphereGlyph_Lua );

#endif //_KVSSPHEREGLYPH_LUA_H_

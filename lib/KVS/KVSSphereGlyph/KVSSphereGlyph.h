/**
 * @file KVSSphereGlyph.h
 */
#ifndef _KVSSPHEREGLYPH_H_
#define _KVSSPHEREGLYPH_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class SphereGlyph;
}

class KVSSphereGlyph : public RefCount
{
public:
    KVSSphereGlyph();
    ~KVSSphereGlyph();

    const char* Renderer() const;
private:
    kvs::SphereGlyph* m_glyph;
};

#endif //_KVSSPHEREGLYPH_H_

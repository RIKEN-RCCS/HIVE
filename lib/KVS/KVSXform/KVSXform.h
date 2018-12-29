/**
 * @file KVSXform.cpp
 */
#ifndef _KVSXFORM_H_
#define _KVSXFORM_H_

#include "Ref.h"
#include <kvs/Matrix33>
#include <kvs/Vector3>

namespace kvs {
    class Xform;
}

class KVSXform : public RefCount
{
public:
    KVSXform();
    ~KVSXform();
    bool SetRotation( float rx, float ry, float rz );
    bool SetScaling( float sx, float sy, float sz );
    bool SetTranslation( float tx, float ty, float tz );
    const char* Xform() const;

private:
    kvs::Mat3 m_rotation;
    kvs::Vec3 m_scaling;
    kvs::Vec3 m_translation;
    mutable kvs::Xform* m_xform;
};

#endif //_KVSXFORM_H_

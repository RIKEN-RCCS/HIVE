/**
 * @file KVSPointGenerator.h
 */
#ifndef _KVSPOINTGENERATOR_H_
#define _KVSPOINTGENERATOR_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class PointObject;
    template <class T> class Vector3;
    typedef Vector3<int> vector3i;
}

class KVSPointGenerator : public RefCount
{
public:
    KVSPointGenerator();
    ~KVSPointGenerator();
    const char* Object() const;
    bool SetMinCoord( int, int, int );
    bool SetMaxCoord( int, int, int );
    bool Generate();

private:
    kvs::PointObject* m_point;
    kvs::vector3i* m_min_coord;
    kvs::vector3i* m_max_coord;
};

#endif //_KVSPOINTGENERATOR_H_

/**
 * @file KVSStreamline.h
 */
#ifndef _KVSSTREAMLINE_H_
#define _KVSSTREAMLINE_H_

#include "Ref.h"
#include "Buffer.h"
#include "kvs/Vector3"

namespace kvs {
    class Streamline;
    class StructuredVolumeObject;
    class TransferFunction;
}

class KVSStreamline : public RefCount
{
public:
    KVSStreamline();
    ~KVSStreamline();
    const char* Object() const;
    bool SetVolumeObject( void* obj );
    bool SetMinCoord( float x, float y, float z );
    bool SetMaxCoord( float x, float y, float z );
    bool SetDelta( float dx, float dy, float dz );
    bool SetTransferFunction( void* tf );
    bool Exec();

private:
    kvs::Streamline* m_object;
    kvs::StructuredVolumeObject* m_volume;
    kvs::TransferFunction* m_tf;
    kvs::Vector3<float> m_max_coord;
    kvs::Vector3<float> m_min_coord;
    kvs::Vector3<float> m_delta;
};

#endif //_KVSSTREAMLINE_H_

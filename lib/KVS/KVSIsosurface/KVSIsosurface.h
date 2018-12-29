/**
 * @file KVSIsosurface.h
 */
#ifndef _KVSISOSURFACE_H_
#define _KVSISOSURFACE_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class Isosurface;
    class VolumeObjectBase;
}

class KVSIsosurface : public RefCount
{
public:
    KVSIsosurface();
    ~KVSIsosurface();

    const char* Object() const;
    bool SetTransferFunction( void* tf );
    bool SetVolumeObject( void* volume );
    bool SetIsolevel( float isolevel);	
private:
    kvs::Isosurface* m_object;
    kvs::VolumeObjectBase* m_volume;
};

#endif //_KVSISOSURFACE_H_

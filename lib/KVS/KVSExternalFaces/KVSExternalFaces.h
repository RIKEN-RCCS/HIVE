/**
 * @file KVSExternalFaces.h
 */
#ifndef _KVSEXTERNALFACES_H_
#define _KVSEXTERNALFACES_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class ExternalFaces;
    class VolumeObjectBase;
}

class KVSExternalFaces : public RefCount
{
public:
    KVSExternalFaces();
    ~KVSExternalFaces();

    const char* Object() const;
    bool SetTransferFunction( void* tf );
    bool SetVolumeObject( void* volume );

private:
    kvs::ExternalFaces* m_object;
    kvs::VolumeObjectBase* m_volume;
};

#endif //_KVSEXTERNALFACES_H_

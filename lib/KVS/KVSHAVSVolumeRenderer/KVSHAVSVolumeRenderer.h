/**
 * @file KVSHAVSVolumeRenderer.h
 */
#ifndef _KVSHAVSVOLUMERENDERER_H_
#define _KVSHAVSVOLUMERENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class HAVSVolumeRenderer;
}

class KVSHAVSVolumeRenderer : public RefCount
{
public:
    KVSHAVSVolumeRenderer();
    ~KVSHAVSVolumeRenderer();

    const char* Renderer() const;
    bool SetKBufferSize( int size );

private:
    kvs::HAVSVolumeRenderer* m_renderer;
};

#endif //_KVSHAVSVOLUMERENDERER_H_

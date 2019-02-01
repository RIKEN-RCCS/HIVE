/**
 * @file KVSParticleBasedRenderer.h
 */
#ifndef _KVSPARTICLEBASEDRENDERER_H_
#define _KVSPARTICLEBASEDRENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class ParticleBasedRenderer;
}

class KVSParticleBasedRenderer : public RefCount
{
public:
    KVSParticleBasedRenderer();
    ~KVSParticleBasedRenderer();

    const char* Renderer() const;
    bool SetSubpixelLevel( int level );
    bool EnableShading( bool isEnable );

private:
    kvs::ParticleBasedRenderer* m_renderer;
};

#endif //_KVSPARTICLEBASEDRENDERER_H_

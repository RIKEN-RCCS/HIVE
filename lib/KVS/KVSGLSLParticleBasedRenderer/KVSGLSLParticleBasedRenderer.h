/**
 * @file KVSGLSLParticleBasedRenderer.h
 */
#ifndef _KVSGLSLPARTICLEBASEDRENDERER_H_
#define _KVSGLSLPARTICLEBASEDRENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    namespace glsl {
	class ParticleBasedRenderer;
    }
}

class KVSGLSLParticleBasedRenderer : public RefCount
{
 public:
    KVSGLSLParticleBasedRenderer();
    ~KVSGLSLParticleBasedRenderer();

    const char* Renderer() const;
    bool EnableLODControl( bool isEnable );
    bool SetRepetitionLevel( int level );
    bool EnableShading( bool isEnable );

 private:
    kvs::glsl::ParticleBasedRenderer* m_renderer;
};

#endif //_KVSGLSLPARTICLEBASEDRENDERER_H_

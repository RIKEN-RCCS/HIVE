/**
 * @file KVSGLSLRayCastingRenderer.h
 */
#ifndef _KVSGLSLRAYCASTINGRENDERER_H_
#define _KVSGLSLRAYCASTINGRENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class RendererBase;
}

class KVSGLSLRayCastingRenderer : public RefCount
{
public:
    KVSGLSLRayCastingRenderer();
    ~KVSGLSLRayCastingRenderer();

    const char* Renderer() const;
private:
    kvs::RendererBase* m_renderer;
};

#endif //_KVSGLSLRAYCASTINGRENDERER_H_

/**
 * @file KVSStylizedLineRenderer.h
 */
#ifndef _KVSSTYLIZEDLINERENDERER_H_
#define _KVSSTYLIZEDLINERENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class StylizedLineRenderer;
}

class KVSStylizedLineRenderer : public RefCount
{
public:
    KVSStylizedLineRenderer();
    ~KVSStylizedLineRenderer();

    const char* Renderer() const;
    bool EnableShading( bool isEnable );

private:
    kvs::StylizedLineRenderer* m_renderer;
};

#endif //_KVSSTYLIZEDLINERENDERER_H_

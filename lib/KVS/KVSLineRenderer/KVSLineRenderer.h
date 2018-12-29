/**
 * @file KVSLineRenderer.h
 */
#ifndef _KVSLINERENDERER_H_
#define _KVSLINERENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class LineRenderer;
}

class KVSLineRenderer : public RefCount
{
public:
    KVSLineRenderer();
    ~KVSLineRenderer();

    const char* Renderer() const;
    bool SetEnabledShading( bool enable );

private:
    kvs::LineRenderer* m_renderer;
};

#endif //_KVSLINERENDERER_H_

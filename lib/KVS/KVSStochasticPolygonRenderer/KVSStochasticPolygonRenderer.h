/**
 * @file KVSStochasticPolygonRenderer.h
 */
#ifndef _KVSSTOCHASTICPOLYGONRARENDERER_H_
#define _KVSSTOCHASTICPOLYGONRARENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class StochasticPolygonRenderer;
}

class KVSStochasticPolygonRenderer : public RefCount
{
 public:
    KVSStochasticPolygonRenderer();
    ~KVSStochasticPolygonRenderer();

    const char* Renderer() const;
    bool EnableShading( bool isEnable );
 private:
    kvs::StochasticPolygonRenderer* m_renderer;
};

#endif //_KVSSTOCHASTICPOLYGONRARENDERER_H_

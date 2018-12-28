/**
 * @file KVSStochasticTetrahedraRenderer.h
 */
#ifndef _KVSSTOCHASTICTETRAHEDRARENDERER_H_
#define _KVSSTOCHASTICTETRAHEDRARENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class StochasticTetrahedraRenderer;
    class TransferFunction;
}

class KVSStochasticTetrahedraRenderer : public RefCount
{
 public:
    KVSStochasticTetrahedraRenderer();
    ~KVSStochasticTetrahedraRenderer();

    const char* Renderer() const;
    bool EnableShading( bool isEnable );
    bool SetTransferFunction( void* );
    
 private:
    kvs::StochasticTetrahedraRenderer* m_renderer;
};

#endif //_KVSSTOCHASTICTETRAHEDRARENDERER_H_

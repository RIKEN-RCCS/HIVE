/**
 * @file KVSRayCastingRenderer.h
 */
#ifndef _KVSRAYCASTINGRENDERER_H_
#define _KVSRAYCASTINGRENDERER_H_

#include "Ref.h"
#include "Buffer.h"

namespace kvs {
    class RayCastingRenderer;
    class TransferFunction;
}

class KVSRayCastingRenderer : public RefCount
{
 public:
    KVSRayCastingRenderer();
    ~KVSRayCastingRenderer();

    const char* Renderer() const;
    bool SetOpaqueValue( float value );
    bool SetSamplingStep( float step );
    bool SetTransferFunction( void* );
 private:
    kvs::RayCastingRenderer* m_renderer;
};

#endif //_KVSRAYCASTINGRENDERER_H_

/**
 * @file KVSGLSLRayCastingRenderer.cpp
  */
#include "KVSGLSLRayCastingRenderer.h"
#include <kvs/Message>
#include <kvs/RayCastingRenderer>

/// constructor
KVSGLSLRayCastingRenderer::KVSGLSLRayCastingRenderer()
{
    // Create an sphere glyph renderer.
    kvs::glsl::RayCastingRenderer* renderer = new kvs::glsl::RayCastingRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a glsl raycasting renderer." );
    }
    m_renderer = renderer;

    // Set properties.
    const kvs::TransferFunction transfer_function( 256 );
    const kvs::Real32 sampling_step = 0.5f;
    const kvs::Real32 opaque_value = 0.97f;
    renderer->setSamplingStep( sampling_step );
    renderer->setOpaqueValue( opaque_value );
    renderer->setTransferFunction( transfer_function );
}

/// destructor
KVSGLSLRayCastingRenderer::~KVSGLSLRayCastingRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSGLSLRayCastingRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * @file KVSRayCastingRenderer.cpp
  */
#include "KVSRayCastingRenderer.h"
#include <kvs/Message>
#include <kvs/RayCastingRenderer>

/// constructor
KVSRayCastingRenderer::KVSRayCastingRenderer()
{
    // Create an sphere glyph renderer.
    kvs::RayCastingRenderer* renderer = new kvs::RayCastingRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a raycasting renderer.");
    }
    m_renderer = renderer;

    // Set properties.
    const kvs::TransferFunction transfer_function( 256 );
    const kvs::Real32 sampling_step = 0.5f;
    const kvs::Real32 opaque_value = 0.97f;
    renderer->setSamplingStep( sampling_step );
    renderer->setOpaqueValue( opaque_value );
    renderer->setTransferFunction( transfer_function );
    renderer->enableLODControl();
}

/// destructor
KVSRayCastingRenderer::~KVSRayCastingRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSRayCastingRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * set opaque value
 * @param value [in]
 * @return success(true) or failed(false)
 */
bool KVSRayCastingRenderer::SetOpaqueValue( float value )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setOpaqueValue( value );
    return true;
}

/**
 * set sampling step
 * @param step [in] 
 * @return success(true) or failed(false)
 */
bool KVSRayCastingRenderer::SetSamplingStep( float step )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setSamplingStep( step );
    return true;
}

/**
 * set transfer function
 * @param object [in] transfer function pointer
 * @return success(true) or failed(false)
 */
bool KVSRayCastingRenderer::SetTransferFunction( void* tf )
{
    if ( !m_renderer ) { return false; }
    if ( !tf ) { return false; }
    m_renderer->setTransferFunction( *reinterpret_cast<kvs::TransferFunction*>( tf ) );
    return true;
}

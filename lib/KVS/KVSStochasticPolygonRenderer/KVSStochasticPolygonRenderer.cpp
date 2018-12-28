/**
 * @file KVSStochasticPolygonRenderer.cpp
  */
#include "KVSStochasticPolygonRenderer.h"
#include <kvs/Message>
#include <kvs/StochasticPolygonRenderer>

/// constructor
KVSStochasticPolygonRenderer::KVSStochasticPolygonRenderer()
{
    // Create an sphere glyph renderer.
    kvs::StochasticPolygonRenderer* renderer = new kvs::StochasticPolygonRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a stochastic polygon renderer.");
    }
    m_renderer = renderer;
    renderer->setPolygonOffset( 0.001f );
}

/// destructor
KVSStochasticPolygonRenderer::~KVSStochasticPolygonRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSStochasticPolygonRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * enable shading
 * @param isEnable [in]
 * @return success or failed 
 */
bool KVSStochasticPolygonRenderer::EnableShading( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->setEnabledShading( true );
    } else {
        m_renderer->setEnabledShading( false );
    }
    return true;
}

/**
 * @file KVSStochasticTetrahedraRenderer.cpp
  */
#include "KVSStochasticTetrahedraRenderer.h"
#include <kvs/Message>
#include <kvs/StochasticTetrahedraRenderer>

/// constructor
KVSStochasticTetrahedraRenderer::KVSStochasticTetrahedraRenderer()
{
    kvs::StochasticTetrahedraRenderer* renderer = new kvs::StochasticTetrahedraRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a stochastic tetrahedra renderer." );
    }
    m_renderer = renderer;
}

/// destructor
KVSStochasticTetrahedraRenderer::~KVSStochasticTetrahedraRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSStochasticTetrahedraRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * enable shading
 * @param isEnable [in]
 * @return success or failed 
 */
bool KVSStochasticTetrahedraRenderer::EnableShading( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->setEnabledShading( true );
    } else {
        m_renderer->setEnabledShading( false );
    }
    return true;
}

/**
 * set transfer function
 * @param object [in] transfer function pointer
 * @return success(true) or failed(false)
 */
bool KVSStochasticTetrahedraRenderer::SetTransferFunction( void* tf )
{
    if ( !m_renderer ) { return false; }
    if ( !tf ) { return false; }
    m_renderer->setTransferFunction( *reinterpret_cast<kvs::TransferFunction*>( tf ) );
    return true;
}

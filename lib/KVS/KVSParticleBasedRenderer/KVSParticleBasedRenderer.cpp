/**
 * @file KVSParticleBasedRenderer.cpp
  */
#include "KVSParticleBasedRenderer.h"
#include <kvs/Message>
#include <kvs/ParticleBasedRenderer>

/// constructor
KVSParticleBasedRenderer::KVSParticleBasedRenderer()
{
    kvs::ParticleBasedRenderer* renderer = new kvs::ParticleBasedRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a particle based renderer.");
    }

    renderer->setSubpixelLevel( 1 );
    m_renderer = renderer;
}

/// destructor
KVSParticleBasedRenderer::~KVSParticleBasedRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSParticleBasedRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * set subpixel level
 * @param level [in]
 * @return success(true) or failed(false)
 */
bool KVSParticleBasedRenderer::SetSubpixelLevel( int level )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setSubpixelLevel( level );
    return true;
}

/**
 * enable shading
 * @param isEnable [in]
 * @return success or failed 
 */
bool KVSParticleBasedRenderer::EnableShading( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->setEnabledShading( true );
    } else {
        m_renderer->setEnabledShading( false );
    }
    return true;
}

/**
 * @file KVSGLSLParticleBasedRenderer.cpp
  */
#include "KVSGLSLParticleBasedRenderer.h"
#include <kvs/Message>
#include <kvs/ParticleBasedRenderer>

/// constructor
KVSGLSLParticleBasedRenderer::KVSGLSLParticleBasedRenderer()
{
    // Create an sphere glyph renderer.
    kvs::glsl::ParticleBasedRenderer* renderer = new kvs::glsl::ParticleBasedRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a particle based renderer.");
    }
    m_renderer = renderer;

    // Set properties.
    const size_t repetitions = 4;
    renderer->setRepetitionLevel( repetitions );
    renderer->enableLODControl();
}

/// destructor
KVSGLSLParticleBasedRenderer::~KVSGLSLParticleBasedRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSGLSLParticleBasedRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * enable lod control
 * @param isEnable [in]
 * @return success or failed 
 */
bool KVSGLSLParticleBasedRenderer::EnableLODControl( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->enableLODControl();
    } else {
        m_renderer->disableLODControl();
    }
    return true;
}

/**
 * set repetition level
 * @param level [in]
 * @return success(true) or failed(false)
 */
bool KVSGLSLParticleBasedRenderer::SetRepetitionLevel( int level )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setRepetitionLevel( level );
    return true;
}

/**
 * enable shading
 * @param isEnable [in]
 * @return success or failed 
 */
bool KVSGLSLParticleBasedRenderer::EnableShading( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->setEnabledShading( true );
    } else {
        m_renderer->setEnabledShading( false );
    }
    return true;
}

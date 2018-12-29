/**
 * @file KVSLineRenderer.cpp
  */
#include "KVSLineRenderer.h"
#include <kvs/Message>
#include <kvs/LineRenderer>

/// constructor
KVSLineRenderer::KVSLineRenderer()
{
    m_renderer = NULL;
    kvs::LineRenderer* renderer = new kvs::LineRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a line renderer.");
        return;
    }
    renderer->enableShading();
    m_renderer = renderer;
}

/// destructor
KVSLineRenderer::~KVSLineRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return object pointer
 */ 
const char* KVSLineRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/** 
 * enable shading or not
 * @param enable [in] enable or not
 * @return success(true) or failed(false)
 */
bool KVSLineRenderer::SetEnabledShading( bool enable )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setEnabledShading( enable );
    
    return true;
}

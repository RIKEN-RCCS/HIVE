/**
 * @file KVSStylizedLineRenderer.cpp
  */
#include "KVSStylizedLineRenderer.h"
#include <kvs/Message>
#include <kvs/StylizedLineRenderer>

/// constructor
KVSStylizedLineRenderer::KVSStylizedLineRenderer()
{
    m_renderer = NULL;
    // Create an sphere glyph renderer.
    kvs::StylizedLineRenderer* renderer = new kvs::StylizedLineRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a stylized line renderer.");
        return;
    }
    m_renderer = renderer;

    // Set properties.
    renderer->setShader( kvs::Shader::BlinnPhong() );
    renderer->enableShading();
}

/// destructor
KVSStylizedLineRenderer::~KVSStylizedLineRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return object pointer
 */ 
const char* KVSStylizedLineRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/** 
 * enable shading or not
 * @param isEnable [in] 
 * @return success(true) or failed(false)
 */
bool KVSStylizedLineRenderer::EnableShading( bool isEnable )
{
    if ( !m_renderer ) { return false; }
    if ( isEnable ) {
        m_renderer->enableShading();
    } else {
        m_renderer->disableShading();
    }
    return true;
}

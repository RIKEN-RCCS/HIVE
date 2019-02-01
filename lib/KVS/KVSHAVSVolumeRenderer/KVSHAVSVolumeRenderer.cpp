/**
 * @file KVSHAVSVolumeRenderer.cpp
  */
#include "KVSHAVSVolumeRenderer.h"
#include <kvs/Message>
#include <kvs/HAVSVolumeRenderer>

/// constructor
KVSHAVSVolumeRenderer::KVSHAVSVolumeRenderer()
{
    kvs::HAVSVolumeRenderer* renderer = new kvs::HAVSVolumeRenderer();
    if ( !renderer )
    {
        kvsMessageError( "Cannot creat a HAVS-volume renderer.");
    }
    m_renderer = renderer;
}

/// destructor
KVSHAVSVolumeRenderer::~KVSHAVSVolumeRenderer()
{
    delete m_renderer;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSHAVSVolumeRenderer::Renderer() const
{
    return reinterpret_cast<const char*>( m_renderer );
}

/**
 * set K buffer size
 * @param size [in]
 * @return success(true) or failed(false)
 */
bool KVSHAVSVolumeRenderer::SetKBufferSize( int size )
{
    if ( !m_renderer ) { return false; }
    m_renderer->setKBufferSize( size );
    return true;
}

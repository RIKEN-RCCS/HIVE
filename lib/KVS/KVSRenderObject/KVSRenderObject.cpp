/**
 * @file KVSRenderObject.cpp
 */
#include "KVSRenderObject.h"
#include <iostream>
#include <kvs/GeometryObjectBase>
#include <kvs/LineRenderer>
#include <kvs/Message>
#include <kvs/ObjectBase>
#include <kvs/ParticleBasedRenderer>
#include <kvs/PolygonRenderer>
#include <kvs/RayCastingRenderer>
#include <kvs/RGBColor>
#include <kvs/StochasticRendererBase>
#include <kvs/Xform>

/// constructor
KVSRenderObject::KVSRenderObject()
{
    m_object = NULL;
    m_renderer = NULL;
    m_renderer_input = NULL;
    m_shader_flag = true;
    m_shading_flag = true;
    m_show_flag = true;
    m_xform = NULL;
}

/// destructor
KVSRenderObject::~KVSRenderObject()
{
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSRenderObject::Object() const
{
    if ( m_object ) {
        if ( m_xform )
            m_object->setXform( *m_xform );
	if ( m_show_flag ) m_object->show();
	else m_object->hide();
       
	return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
    }
    return NULL;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSRenderObject::Renderer() const
{
    if ( m_renderer ) {
        m_renderer->setEnabledShading( m_shading_flag );
	return reinterpret_cast<const char*>( m_renderer );
    }
    return NULL;
}

/**
 * release renderer
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::Release()
{
    if ( m_renderer ) {
	kvs::StochasticRendererBase* base \
            = dynamic_cast<kvs::StochasticRendererBase*>( m_renderer );
	if ( base != NULL ) base->release();
    }
    return true;
}

/**
 * set object
 * @param object [in] object pointer
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetObject( void* object )
{
    if ( m_object != object )
    {
        if ( object )
        {
            if ( static_cast<kvs::ObjectBase*>( object )->objectType() \
                 != kvs::ObjectBase::Geometry )
            {
                kvsMessageError( "Input object is not geometry object." );
                m_object = NULL;
                select_renderer();
                return false;
            }
            m_object = static_cast<kvs::GeometryObjectBase*>( object );
            m_object->print( std::cout );
        }
        else
            m_object = NULL;
        select_renderer();
    }
    return true;
}

/**
 * set renderer
 * @param renderer [in] renderer pointer
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetRenderer( void* renderer ) {
    if ( m_renderer_input != renderer )
        if ( renderer )
        {
            m_renderer_input = renderer;
            m_renderer = static_cast<kvs::RendererBase*>( m_renderer_input );
        }
        else
        {
            m_renderer_input = NULL;
            return select_renderer();
        }
    return true;
}

/**
 * set shader flag
 * @param shader [in] shader flag
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetShaderFlag( bool shader )
{
    if ( m_shader_flag != shader )
    {
        m_shader_flag = shader;
        select_renderer();
    }
    return true;
}

/**
 * set shading flag
 * @param shading [in] shading flag
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetShadingFlag( bool shading )
{
    m_shading_flag = shading;
    return true;
}

/**
 * set show flag
 * @param show [in] show flag
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetShowFlag( bool show )
{
    m_show_flag = show;
    return true;
}

/**
 * set xform
 * @param xform [in] xform pointer
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::SetXform( void* xform ) {
    if ( xform )
        m_xform = static_cast<kvs::Xform*>( xform );
    else
        m_xform = NULL;
    return true;
}

/**
 * select a renderer which suits the data type of the object
 * @return success(true) or failed(false)
 */
bool KVSRenderObject::select_renderer()
{
    std::string name;
    if ( !(m_object && !m_renderer_input) )
    {
        m_renderer = static_cast<kvs::RendererBase*>( m_renderer_input );
        return true;
    }
    else
    {
        switch ( m_object->geometryType() )
        {
        case kvs::GeometryObjectBase::Point :
            if ( m_shader_flag )
            {
                m_renderer = new kvs::glsl::ParticleBasedRenderer;
                name = "GLSL ParticleBasedRenderer";
            }
            else
            {
                m_renderer = new kvs::ParticleBasedRenderer;
                name = "ParticleBasedRenderer";
            }
            break;
        case kvs::GeometryObjectBase::Line :
            if ( m_shader_flag )
            {
                m_renderer = new kvs::glsl::LineRenderer;
                name = "GLSL LineRenderer";
            }
            else
            {
                m_renderer = new kvs::LineRenderer;
                name = "LineRenderer";
            }
            break;
        case kvs::GeometryObjectBase::Polygon :
            if ( m_shader_flag )
            {
                m_renderer = new kvs::glsl::PolygonRenderer;
                name = "GLSL PolygonRenderer";
            }
            else
            {
                m_renderer = new kvs::PolygonRenderer;
                name = "PolygonRenderer";
            }
            break;
        dafault :
            break;
        }
    }
    std::cout << "Renderer : " << name << std::endl;
    return true;  
}

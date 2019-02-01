/**
 * @file KVSGenericObject.cpp
 */
#include "KVSGenericObject.h"
#include <kvs/ObjectBase>
#include <kvs/GeometryObjectBase>
#include <kvs/PolygonObject>
#include <kvs/StochasticRendererBase>
#include <kvs/ParticleBasedRenderer>
#include <kvs/StylizedLineRenderer>
#include <kvs/LineRenderer>
#include <kvs/StochasticPolygonRenderer>
#include <kvs/RayCastingRenderer>
#include <kvs/StochasticTetrahedraRenderer>
#include <kvs/Xform>
#include <kvs/RGBColor>
#include <iostream>

/// constructor
KVSGenericObject::KVSGenericObject()
{
    m_dataType = UnknownDataType;
    m_renderer = NULL;
    m_object = NULL;
    m_translate[0] = m_translate[1] = m_translate[2] = 0;
    m_rot[0]       = m_rot[1]       = m_rot[2]       = 0;
    m_scale[0]     = m_scale[1]     = m_scale[2]     = 1;
    m_color[0]     = m_color[0]     = m_color[0]     = m_color[0] = -1;
    m_show_flag = true;
    m_shading_flag = true;
    m_gpu_flag = true;
}

/// destructor
KVSGenericObject::~KVSGenericObject()
{
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSGenericObject::Object() const
{
    if ( m_object ) {
        kvs::Vec3 translation( m_translate[0], m_translate[1], m_translate[2] );
        kvs::Mat3 rotation( kvs::Mat3::RotationY( m_rot[1] ) \
                            * kvs::Mat3::RotationX( m_rot[0] ) \
                            * kvs::Mat3::RotationZ( m_rot[2] ) );
        kvs::Vec3 scaling( m_scale[0], m_scale[1], m_scale[2] );
        kvs::Xform trs = kvs::Xform::Translation( translation );
	kvs::Xform rot = kvs::Xform::Rotation( rotation );
	kvs::Xform scl = kvs::Xform::Scaling( scaling );
	m_object->setXform( trs * rot * scl );
        if ( (m_dataType == GeometryPoint) || (m_dataType == GeometryLine) \
             || (m_dataType == GeometryPolygon) )
        {
            if ( (m_color[0] >= 0) && (m_color[1] >= 0) && (m_color[2] >= 0) )
            {
                kvs::RGBColor color = kvs::RGBColor( m_color[0], m_color[1], m_color[2] );
                dynamic_cast<kvs::GeometryObjectBase*>( m_object )->setColor( color );
            }
            if ( (m_dataType == GeometryPolygon) && (m_color[3] >= 0) )
                dynamic_cast<kvs::PolygonObject*>( m_object )->setOpacity( m_color[3] );
        }
	if ( m_show_flag ) m_object->show();
	else m_object->hide();
        m_renderer->setEnabledShading( m_shading_flag );
        
	return reinterpret_cast<const char*>( m_object );
    }
    return NULL;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSGenericObject::Renderer() const
{
    if ( m_renderer ) {
	return reinterpret_cast<const char*>( m_renderer );
    }
    return NULL;
}

/**
 * set object
 * @param object [in] object pointer
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetObject( void * obj )
{
    if ( !obj ) m_renderer = NULL;
    else if ( obj != m_object )
    {
        m_object = reinterpret_cast<kvs::ObjectBase*>( obj );
        m_object->print( std::cout );
        if( !CheckDataType() || !SelectRenderer() ) return false;
    }  
    return true;
}

/**
 * set translate
 * @param tx [in] translate x
 * @param ty [in] translate y
 * @param tz [in] translate z
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetTranslate( float tx, float ty, float tz ) {
    m_translate[0] = tx;
    m_translate[1] = ty;
    m_translate[2] = tz;
    return true;
}

/**
 * set rotate
 * @param rx [in] rotate x
 * @param ry [in] rotate y
 * @param rz [in] rotate z
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetRotate( float rx, float ry, float rz ) {
    m_rot[0] = rx;
    m_rot[1] = ry;
    m_rot[2] = rz;
    return true;
}

/**
 * set scale
 * @param sx [in] scale x
 * @param sy [in] scale y
 * @param sz [in] scale z
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetScale( float sx, float sy, float sz ) {
    m_scale[0] = sx;
    m_scale[1] = sy;
    m_scale[2] = sz;
    return true;
}

/**
 * set color
 * @param red [in] red
 * @param green [in] green
 * @param blue [in] blue
 * @param opacity [in] opacity
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetColor( float red, float green, float blue, float opacity ) {
    m_color[0] = red;
    m_color[1] = green;
    m_color[2] = blue;
    m_color[3] = opacity;
    return true;
}

/**
 * release object
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::Release()
{
    if ( m_renderer ) {
	kvs::StochasticRendererBase* base \
            = dynamic_cast<kvs::StochasticRendererBase*>(m_renderer);
	if ( base != NULL ) base->release();
    }
    return true;
}

/**
 * set show flag
 * @param show [in] show flag
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetShowFlag( bool show )
{
    m_show_flag = show;
    return true;
}

/**
 * set shading flag
 * @param shading [in] shading flag
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetShadingFlag( bool shading )
{
    m_shading_flag = shading;
    return true;
}

/**
 * set gpu flag
 * @param gpu [in] gpu flag
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SetGPUFlag( bool gpu )
{
    if ( m_object && (m_gpu_flag != gpu) )
    {
        m_gpu_flag = gpu;
        if ( !SelectRenderer() ) return false;
        else return true;
    }
    m_gpu_flag = gpu;
    
    return true;
}

/**
 * select a renderer which suits the data type of the object
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::SelectRenderer()
{
    std::string name;
    switch ( m_dataType ) {
    case GeometryPoint :
        if ( m_gpu_flag )
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
    case GeometryLine :
        if ( m_gpu_flag )
        {
            m_renderer = new kvs::StylizedLineRenderer;
            name = "StylizedLineRenderer";
        }
        else
        {
            m_renderer = new kvs::LineRenderer;
            name = "LineRenderer";
        }
        break;
    case GeometryPolygon :
        if ( m_gpu_flag )
        {
            m_renderer = new kvs::StochasticPolygonRenderer;
            name = "StochasticPolygonRenderer";
        }
        break;
    case StructuredVolume :
        if ( m_gpu_flag )
        {
            m_renderer = new kvs::glsl::RayCastingRenderer;
            name = "GLSL RayCastingRenderer";
        }
        else
        {
            m_renderer = new kvs::RayCastingRenderer;
            name = "RayCastingRenderer";
        }
        break;
    case UnstructuredVolume :
        if ( m_gpu_flag )
        {
            m_renderer = new kvs::StochasticTetrahedraRenderer;
            name = "StochasticTetrahedraRenderer";
        }
        break;
    dafault :
        break;
    }
    
    if ( m_renderer )
    {
        std::cout << "Renderer : " << name << std::endl;
        return true;
    }
    
    std::cerr << "This data type is not supported with this module." << std::endl;
    std::cerr << "Use KVSObject and select a renderer by yourself." << std::endl;    
    return false;
}

/**
 * check input data type
 * @return success(true) or failed(false)
 */
bool KVSGenericObject::CheckDataType()
{
    if ( !m_object ) 
    {
        std::cerr << "No input data." << std::endl;
        return false;
    }

    std::cout << "Data type  : ";
    switch ( m_object->objectType() ) {
    case kvs::ObjectBase::Geometry :
        switch ( dynamic_cast<kvs::GeometryObjectBase*>( m_object )->geometryType() ) {
        case kvs::GeometryObjectBase::Point :
            m_dataType = GeometryPoint;
            std::cout << "Geometry point" << std::endl;
            break;
        case kvs::GeometryObjectBase::Line :
            m_dataType = GeometryLine;
            std::cout << "Geometry line" << std::endl;
            break;
        case kvs::GeometryObjectBase::Polygon :
            m_dataType = GeometryPolygon;
            std::cout << "Geometry polygon" << std::endl;
            break;
        default :
            break;
        }
        break;
    case kvs::ObjectBase::Volume :
        switch ( dynamic_cast<kvs::VolumeObjectBase*>( m_object )->volumeType() ) {
        case kvs::VolumeObjectBase::Structured :
            m_dataType = StructuredVolume;
            std::cout << "Structured volume" << std::endl;
            break;
        case kvs::VolumeObjectBase::Unstructured :
            m_dataType = UnstructuredVolume;
            std::cout << "Unstructured volume" << std::endl;
            break;
        dafault :
            break;
        }
        break;
    default :
        break;
    }
    
    if ( m_dataType == UnknownDataType )
    {
        std::cout << "Unknown" << std::endl;
        std::cerr << "This data type is not supported with this module." << std::endl;
        std::cerr << "Use KVSObject and select a renderer by yourself." << std::endl;
        return false;
    }

    return true;
}

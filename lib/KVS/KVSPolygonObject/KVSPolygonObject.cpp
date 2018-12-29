/**
 * @file KVSPolygonObject.cpp
 */
#include "KVSPolygonObject.h"
#include <kvs/PolygonObject>
#include <kvs/StochasticRendererBase>
#include <kvs/Message>
#include <kvs/Xform>
#include <kvs/RGBColor>

/// constructor
KVSPolygonObject::KVSPolygonObject()
{
    m_renderer = NULL;
    m_object = NULL;
    m_translate[0] = m_translate[1] = m_translate[2] = 0;
    m_rot[0]       = m_rot[1]       = m_rot[2]       = 0;
    m_scale[0]     = m_scale[1]     = m_scale[2]     = 1;
    m_color[0]     = m_color[1]     = m_color[2]     = m_color[3] = -1;
    m_show_flag = true;
}

/// destructor
KVSPolygonObject::~KVSPolygonObject()
{
}

/**
 * set object
 * @param object [in] object pointer
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::SetPolygonObject( void * obj )
{
    m_object = reinterpret_cast<kvs::PolygonObject*>( obj );
    return true;
}

/**
 * set renderer
 * @param renderer [in] renderer pointer
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::SetRenderer( void* renderer )
{
    m_renderer = reinterpret_cast<kvs::RendererBase*>( renderer );
    return true;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSPolygonObject::PolygonObject() const
{
    if ( m_object ) {
	kvs::Xform trs = kvs::Xform::Translation( kvs::Vec3(m_translate[0],m_translate[1],m_translate[2]) );
	kvs::Xform rot = kvs::Xform::Rotation( kvs::Mat3::RotationY(m_rot[1]) * kvs::Mat3::RotationX(m_rot[0]) * kvs::Mat3::RotationZ(m_rot[2]) );
	kvs::Xform scl = kvs::Xform::Scaling( kvs::Vec3(m_scale[0],m_scale[1],m_scale[2]) );
	m_object->setXform( trs * rot * scl );
	m_object->setColor( kvs::RGBColor(m_color[0], m_color[1], m_color[2]) );
	m_object->setOpacity( m_color[3] );
	if ( m_show_flag ) m_object->show();
	else m_object->hide();
    
	return reinterpret_cast<const char*>( m_object );
    }
    return NULL;
}

/**
 * get renderer
 * @return renderer pointer
 */ 
const char* KVSPolygonObject::Renderer() const
{
    if ( m_renderer ) {
	return reinterpret_cast<const char*>( m_renderer );
    }
    return NULL;
}

/**
 * set translate
 * @param tx [in] translate x
 * @param ty [in] translate y
 * @param tz [in] translate z
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::SetTranslate( float tx, float ty, float tz ) {
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
bool KVSPolygonObject::SetRotate( float rx, float ry, float rz ) {
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
bool KVSPolygonObject::SetScale( float sx, float sy, float sz ) {
    m_scale[0] = sx;
    m_scale[1] = sy;
    m_scale[2] = sz;
    return true;
}

/**
 * set color
 * @param r [in] color red
 * @param g [in] color green
 * @param b [in] color blue
 * @param a [in] color alpha
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::SetColor( float r, float g, float b,  float a ) {
    if ( (r >= 0) && (g >= 0) && (b >= 0) ) {
	m_color[0] = r;
	m_color[1] = g;
	m_color[2] = b;
    }
    if ( a >= 0 )
	m_color[3] = a;
    return true;
}

/**
 * release object
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::Release()
{
    if ( m_renderer ) {
	static_cast<kvs::StochasticRendererBase*>(m_renderer)->release();
    }
    return true;
}

/**
 * set show flag
 * @param show [in] show flag
 * @return success(true) or failed(false)
 */
bool KVSPolygonObject::SetShowFlag( bool show_flag )
{
    m_show_flag = show_flag;
    return true;
}

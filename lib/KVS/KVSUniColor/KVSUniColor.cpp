/**
 * @file KVSUniColor.cpp
 */
#include "KVSUniColor.h"
#include <kvs/GeometryObjectBase>
#include <kvs/Message>
#include <kvs/ObjectBase>
#include <kvs/PolygonObject>
#include <kvs/RGBColor>

/// constructor
KVSUniColor::KVSUniColor()
{
    m_object = NULL;
    m_input = NULL;
}

/// destructor
KVSUniColor::~KVSUniColor()
{
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSUniColor::Object() const
{
    if ( m_object )
        return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
    else
        return NULL;
}

/**
 * set color
 * @param red     [in] red
 * @param green   [in] green
 * @param blue    [in] blue
 * @param opacity [in] opacity
 * @return success(true) or failed(false)
 */
bool KVSUniColor::SetColor( int red, int green, int blue, int opacity )
{
    if ( m_object )
    {
        if ( (red >= 0) && (green >= 0) && (blue >= 0) )
        {
            kvs::RGBColor color = kvs::RGBColor( red, green, blue );
            m_object->setColor( color );
        }
        if ( (m_object->geometryType() == kvs::GeometryObjectBase::Polygon) && (opacity >= 0) )
        {
            std::cout << "[DEBUG] is polygon." << std::endl;
            dynamic_cast<kvs::PolygonObject*>( m_object )->setOpacity( opacity );
    }
        return true;
}
    return false;
}

/**
 * set geometry object
 * @param geometry [in] geometry object
 * @return success(true) or failed(false)
 */
bool KVSUniColor::SetGeometryObject( void* geometry )
{
    if ( geometry && (m_input != geometry) )
    {
        m_input = geometry;
        kvs::GeometryObjectBase* geometry_object;
        geometry_object = static_cast<kvs::GeometryObjectBase*>( geometry );
        if ( geometry_object->geometryType() == kvs::GeometryObjectBase::Polygon )
        {
            kvs::PolygonObject* polygon_object = new kvs::PolygonObject();
            polygon_object->deepCopy( *dynamic_cast<kvs::PolygonObject*>( geometry_object ) );
            m_object = polygon_object;
        }
        else
        {
            m_object = new kvs::GeometryObjectBase();
            m_object->deepCopy( *geometry_object );
        }
        return true;
    }
    return false;
}

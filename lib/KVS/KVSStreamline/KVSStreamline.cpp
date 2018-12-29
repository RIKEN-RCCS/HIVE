/**
 * @file KVSStreamline.cpp
 */
#include "KVSStreamline.h"
#include <kvs/Message>
#include <kvs/PointObject>
#include <kvs/StructuredVolumeObject>
#include <kvs/Streamline>

/// constructor
KVSStreamline::KVSStreamline()
{
    m_object = new kvs::Streamline;
    if ( !m_object )
    {
        kvsMessageError( "Cannot create a stream line object." );
        return;
    }
    m_max_coord.zero();
    m_min_coord.zero();
    m_delta = kvs::Vector3<float>().All( 1 );
    m_tf = new kvs::TransferFunction( 256 );
}

/// destructor
KVSStreamline::~KVSStreamline()
{
    delete m_object;
    delete m_volume;
    delete m_tf;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSStreamline::Object() const
{
    return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
}

/**
 * set volume object
 * @param obj [in] volume object
 * @return success(true) or failed(false)
 */
bool KVSStreamline::SetVolumeObject( void* obj )
{
    m_volume = reinterpret_cast<kvs::StructuredVolumeObject*>( obj );
    if ( !m_volume )
    {
        kvsMessageError( "Cannot set the volume object." );
        return false;
    }
    m_volume->print( std::cout );
    return true;
}

/**
 * set maximum coordinate of seed points
 * @param x, y, z [in] coordinate
 * @return success(true) or failed(false)
 */
bool KVSStreamline::SetMaxCoord( float x, float y, float z )
{
    m_max_coord.x() = x;
    m_max_coord.y() = y;
    m_max_coord.z() = z;
    
    return true;
}

/**
 * set minimum coordinate of seed points
 * @param x, y, z [in] coordinate
 * @return success(true) or failed(false)
 */
bool KVSStreamline::SetMinCoord( float x, float y, float z )
{
    m_min_coord.x() = x;
    m_min_coord.y() = y;
    m_min_coord.z() = z;
    
    return true;
}

/**
 * set stride of seed points
 * @param dx, dy, dz [in] stride in each directions
 * @return success(true) or failed(false)
 */
bool KVSStreamline::SetDelta( float dx, float dy, float dz )
{
    m_delta.x() = dx;
    m_delta.y() = dy;
    m_delta.z() = dz;
    
    return true;
}

/**
 * set transfer function
 * @param tf [in] pointer of transfer function
 * @return success(true) or failed(false)
 */
bool KVSStreamline::SetTransferFunction( void* tf )
{
    if ( !tf ) return false;
    m_tf = reinterpret_cast<kvs::TransferFunction*>( tf );
    return true;
}

/**
 * excute streamline creation
 * @return success(true) or failed(false)
 */
bool KVSStreamline::Exec()
{
    if ( !m_object || !m_volume ) return false;
    std::vector<kvs::Real32> coord;
    if ( (m_min_coord.x() <= m_max_coord.x()) && (m_min_coord.y() <= m_max_coord.y()) \
         && (m_min_coord.z() <= m_max_coord.z()) && (m_delta.x() > 0) \
         && (m_delta.y() > 0) && (m_delta.z() > 0))
    {
        for ( float k = m_min_coord.z(); k <= m_max_coord.z(); k += m_delta.z() )
        {
            for ( float j = m_min_coord.y(); j <= m_max_coord.y(); j += m_delta.y() )
            {
                for ( float i = m_min_coord.x(); i <= m_max_coord.x(); i += m_delta.x() )
                {
                    coord.push_back( static_cast<kvs::Real32>(i) );
                    coord.push_back( static_cast<kvs::Real32>(j) );
                    coord.push_back( static_cast<kvs::Real32>(k) );
                }
            }
        }
        kvs::PointObject* point = new kvs::PointObject;
        point->setCoords( kvs::ValueArray<kvs::Real32>( coord ) );
        m_object->setTransferFunction( *m_tf );
        m_object->setSeedPoints( point );
        m_object->exec( m_volume );
        
        return true;
    }
    return false;
}


/**
 * @file KVSPointGenerator.cpp
 */
#include "KVSPointGenerator.h"
#include <kvs/Message>
#include <kvs/PointObject>
#include <kvs/Vector3>

/// constructor
KVSPointGenerator::KVSPointGenerator()
{
    m_point = NULL;
    m_min_coord = new kvs::Vector3i();
    m_max_coord = new kvs::Vector3i();
}

/// destructor
KVSPointGenerator::~KVSPointGenerator()
{
    delete m_point;
    delete m_min_coord;
    delete m_max_coord;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSPointGenerator::Object() const
{
    return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_point ) );
}

/**
 * set minimum coordinates
 * @param x [in] x coordinate
 * @param y [in] y coordinate
 * @param z [in] z coordinate
 * @return success(true) or failed(false)
 */
bool KVSPointGenerator::SetMinCoord( int x, int y, int z )
{
    kvs::Vector3i v( x, y, z );
    m_min_coord->swap(v);
    return true;
}

/**
 * set maximum coordinates
 * @param x [in] x coordinate
 * @param y [in] y coordinate
 * @param z [in] z coordinate
 * @return success(true) or failed(false)
 */
bool KVSPointGenerator::SetMaxCoord( int x, int y, int z )
{
    kvs::Vector3i v( x, y, z );
    m_max_coord->swap(v);
    return true;
}

/**
 * set volume object
 * @param obj [in] volume object
 * @return success(true) or failed(false)
 */
bool KVSPointGenerator::Generate()
{
    if ( m_point ) {
        delete m_point;
        m_point = NULL;
    }
    m_point = new kvs::PointObject;
    std::vector<kvs::Real32> v;
    for ( int k = m_min_coord->z(); k < m_max_coord->z(); k++ )
    {
        for ( int j = m_min_coord->y(); j < m_max_coord->y(); j++ )
        {
            for ( int i = m_min_coord->x(); i < m_max_coord->x(); i++ )
            {
                v.push_back( static_cast<kvs::Real32>(i) );
                v.push_back( static_cast<kvs::Real32>(j) );
                v.push_back( static_cast<kvs::Real32>(k) );
            }
        }
    }
    m_point->setCoords( kvs::ValueArray<kvs::Real32>( v ) );
    return true;
}

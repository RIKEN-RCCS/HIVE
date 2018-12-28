/**
 * @file KVSTornadoVolumeData.cpp
 */
#include "KVSTornadoVolumeData.h"
#include <kvs/Message>
#include <kvs/StructuredVolumeObject>
#include <kvs/TornadoVolumeData>

/// constructor
KVSTornadoVolumeData::KVSTornadoVolumeData()
{
	m_object = NULL;
    kvs::TornadoVolumeData* object = NULL;
    object = new kvs::TornadoVolumeData( kvs::Vector3ui( 8, 8, 8 ) );

    if ( !object )
    {
        kvsMessageError( "Cannot create a tornado volume object." );
        return;
    }
    m_object = object;
}

/// destructor
KVSTornadoVolumeData::~KVSTornadoVolumeData()
{
    delete m_object;
}

/**
 * get object
 * @return object poinster
 */ 
const char* KVSTornadoVolumeData::Object() const
{
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set time
 * @param time [in]
 * @return success(true) or failed(false)
 */
bool KVSTornadoVolumeData::SetTime( int time )
{
    if ( !m_object ) { return false; }
    m_object->setTime( time );
    return true;
}

/**
 * set resolution
 * @param rx [in] x resolution
 * @param ry [in] y resolution
 * @param rz [in] z resolution
 * @return success(true) or failed(false)
 */
bool KVSTornadoVolumeData::SetResolution( int rx, int ry, int rz )
{
    int preTime = 0;
    if ( m_object ) {
        preTime = m_object->time();
    }
    kvs::TornadoVolumeData* object = new kvs::TornadoVolumeData( kvs::Vector3ui( rx, ry, rz ), preTime );
    if ( !object )
    {
        kvsMessageError( "Cannot create a tornado volume object." );
        return false;
    }
    m_object = object;
    return true;
}

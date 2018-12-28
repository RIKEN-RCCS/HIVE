/**
 * @file KVSHydrogenVolumeData.cpp
 */
#include "KVSHydrogenVolumeData.h"
#include <kvs/Message>
#include <kvs/StructuredVolumeObject>
#include <kvs/HydrogenVolumeData>

/// constructor
KVSHydrogenVolumeData::KVSHydrogenVolumeData()
{
	m_object = NULL;
    kvs::HydrogenVolumeData* object = NULL;
    object = new kvs::HydrogenVolumeData( kvs::Vector3ui( 8, 8, 8 ) );

    if ( !object )
    {
        kvsMessageError( "Cannot create a hydrogen volume data." );
        return;
    }
    m_object = object;
}

/// destructor
KVSHydrogenVolumeData::~KVSHydrogenVolumeData()
{
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSHydrogenVolumeData::Object() const {
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set resolution
 * @param rx [in] x resolution
 * @param ry [in] y resolution
 * @param rz [in] z resolution
 * @return success(true) or failed(false) 
 */
bool KVSHydrogenVolumeData::SetResolution( int rx, int ry, int rz )
{
    kvs::HydrogenVolumeData* object = new kvs::HydrogenVolumeData( kvs::Vector3ui( rx, ry, rz ) );
    if ( !object )
    {
        kvsMessageError( "Cannot create a hydrogen volume data." );
        return false;
    }
    m_object = object;
	return true;
}

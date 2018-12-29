/**
 * @file KVSStructuredVolumeImporter.cpp
 */
#include "KVSStructuredVolumeImporter.h"
#include <kvs/Message>
#include <kvs/StructuredVolumeObject>
#include <kvs/StructuredVolumeImporter>
#include <kvs/TornadoVolumeData>

/// constructor
KVSStructuredVolumeImporter::KVSStructuredVolumeImporter()
{
	m_object = NULL;
    kvs::StructuredVolumeObject* object = NULL;
    if ( !m_file.empty() ) object = new kvs::StructuredVolumeImporter( m_file );
    else            object = new kvs::TornadoVolumeData( kvs::Vector3ui( 8, 8, 8 ) );

    if ( !object )
    {
        kvsMessageError( "Cannot create a structured volume object." );
        return;
    }
    m_object = object;
}

/// destructor
KVSStructuredVolumeImporter::~KVSStructuredVolumeImporter()
{
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSStructuredVolumeImporter::Object() const {
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set file path for import
 * @param file [in] filepath for import
 * @return success(true) or failed(false)
 */
bool KVSStructuredVolumeImporter::SetFile( std::string& file )
{
    if ( file.empty() ) { return false; }
    m_file = file;
    delete m_object;

    kvs::StructuredVolumeObject* object = NULL;
    if ( !m_file.empty() ) object = new kvs::StructuredVolumeImporter( m_file );
    else            object = new kvs::TornadoVolumeData( kvs::Vector3ui( 8, 8, 8 ) );

    if ( !object )
    {
        kvsMessageError( "Cannot create a structured volume object." );
        return false;
    }
    m_object = object;
    return true;
}

/**
 * @file KVSPolygonImporter.cpp
 */
#include "KVSPolygonImporter.h"
#include <kvs/Message>
#include <kvs/PolygonObject>
#include <kvs/PolygonImporter>

/// constructor
KVSPolygonImporter::KVSPolygonImporter()
{
	m_object = NULL;
}

/// destructor
KVSPolygonImporter::~KVSPolygonImporter()
{
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSPolygonImporter::Object() const {
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set file path for import
 * @param file [in] filepath for import
 * @return success(true) or failed(false)
 */
bool KVSPolygonImporter::SetFile( std::string& file )
{
    if ( file.empty() ) { return false; }
    m_file = file;
    delete m_object;

    kvs::PolygonObject* object = NULL;
    if ( !m_file.empty() ) { object = new kvs::PolygonImporter( m_file ); }

    if ( !object )
    {
        kvsMessageError( "Cannot create a polygon object." );
        return false;
    }
    m_object = object;
    return true;
}

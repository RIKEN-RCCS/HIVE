/**
 * @file KVSUnstructuredVolumeImporter.cpp
 */
#include "KVSUnstructuredVolumeImporter.h"
#include <kvs/Message>
#include <kvs/UnstructuredVolumeObject>
#include <kvs/UnstructuredVolumeImporter>

/// constructor
KVSUnstructuredVolumeImporter::KVSUnstructuredVolumeImporter()
{
    m_object = NULL;
    m_min = m_max = 0;
}

/// destructor
KVSUnstructuredVolumeImporter::~KVSUnstructuredVolumeImporter()
{
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSUnstructuredVolumeImporter::Object() const {
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set file path for import
 * @param file [in] filepath for import
 * @return success(true) or failed(false)
 */
bool KVSUnstructuredVolumeImporter::SetFile( std::string& file )
{
    if ( file.empty() ) { return false; }
    m_file = file;
    delete m_object;

    kvs::UnstructuredVolumeObject* object = NULL;
    if ( !m_file.empty() ) { object = new kvs::UnstructuredVolumeImporter( m_file ); }

    if ( !object )
    {
        kvsMessageError( "Cannot create a unstructured volume object." );
        return false;
    }
    
    if ( !object->hasMinMaxValues() ) object->updateMinMaxValues();
    m_min = static_cast<float>( object->minValue() );
    m_max = static_cast<float>( object->maxValue() );

    m_object = object;

    return true;
}

/**
 * get min value
 * @return min value
 */ 
float KVSUnstructuredVolumeImporter::MinValue()
{
    return m_min;
}

/**
 * get max value
 * @return max value
 */ 
float KVSUnstructuredVolumeImporter::MaxValue()
{
    return m_max;
}

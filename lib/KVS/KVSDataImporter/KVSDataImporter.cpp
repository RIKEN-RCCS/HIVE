/**
 * @file KVSDataImporter.cpp
 */
#include "KVSDataImporter.h"
#include <kvs/Message>
#include <kvs/ObjectBase>
#include <kvs/ObjectImporter>
#include <iostream>

/// constructor
KVSDataImporter::KVSDataImporter()
{
    m_object = NULL;
    kvs::ObjectBase* object = new kvs::ObjectBase();
    if ( !object )
    {
        kvsMessageError( "Cannnot create an object base.");
        return;
    }
    m_object = object;
}

/// destructor
KVSDataImporter::~KVSDataImporter()
{
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSDataImporter::Object() const {
    return reinterpret_cast<const char*>( m_object );
}

/**
 * set file path for import and import data
 * @param file [in] filepath for import
 * @return success(true) or failed(false)
 */
bool KVSDataImporter::SetFile( std::string& file )
{
    if ( file == m_file ) return true;
    else if ( file.empty() )
    {
        m_file = "";
        delete m_object;
        m_object = new kvs::ObjectBase();
        return false;   
    }
    else
    {
        m_file = file;
        kvs::ObjectImporter importer( m_file );
        m_object = importer.import();
        m_object->print( std::cout );
    }

    return true;
}

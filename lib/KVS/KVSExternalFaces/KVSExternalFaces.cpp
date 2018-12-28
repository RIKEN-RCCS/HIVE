/**
 * @file KVSExternalFaces.cpp
 */
#include "KVSExternalFaces.h"
#include <kvs/ExternalFaces>
#include <kvs/Message>
#include <kvs/TransferFunction>
#include <kvs/VolumeObjectBase>

/// constructor
KVSExternalFaces::KVSExternalFaces()
{
    m_object = new kvs::ExternalFaces();
}

/// destructor
KVSExternalFaces::~KVSExternalFaces()
{
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSExternalFaces::Object() const
{
    if ( m_object )
    {
        m_object->exec( m_volume );
        return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
    }
    return NULL;
}

/**
 * set transfer function
 * @param tf [in] transfer function
 * @return success(true) or failed(false)
 */
bool KVSExternalFaces::SetTransferFunction( void* tf )
{
    if ( m_object && tf )
    {
        m_object->setTransferFunction( *static_cast<kvs::TransferFunction*>( tf ) );
        return true;
    }
    return false;
}

/**
 * set volume object
 * @param volume [in] volume object
 * @return success(true) or failed(false)
 */
bool KVSExternalFaces::SetVolumeObject( void* volume )
{
    if ( volume )
    {
        m_volume  = static_cast<kvs::VolumeObjectBase*>( volume );
        if ( !m_volume )
        {
            kvsMessageError( "Input object is not volume object." );
            return false;
        }
        return true;
    }
    return false;
}

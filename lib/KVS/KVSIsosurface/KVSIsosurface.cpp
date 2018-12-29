/**
 * @file KVSIsosurface.cpp
 */
#include "KVSIsosurface.h"
#include <kvs/Isosurface>
#include <kvs/Message>
#include <kvs/TransferFunction>
#include <kvs/VolumeObjectBase>

/// constructor
KVSIsosurface::KVSIsosurface()
{
    m_object = new kvs::Isosurface();
}
/// destructor
KVSIsosurface::~KVSIsosurface()
{
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSIsosurface::Object() const
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
bool KVSIsosurface::SetTransferFunction( void* tf )
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
bool KVSIsosurface::SetVolumeObject( void* volume )
{
    if ( volume )
    {
        m_volume  = static_cast<kvs::VolumeObjectBase*>( volume );
        if ( !m_volume )
        {
            kvsMessageError( "Input object is not volume object." );
            return false;
        }
	float i =( m_volume->maxValue() + m_volume->minValue() )* 0.5;
	m_object->setIsolevel( i );
        return true;
    }
    return false;
}

bool KVSIsosurface::SetIsolevel( float isolevel )
{
  if ( m_object )
    {	
      m_object->setIsolevel( isolevel );
      return true;
    }					
    return false;	
}
  
      

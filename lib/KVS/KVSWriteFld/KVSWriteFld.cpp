/**
 * @file KVSWriteFld.cpp
 */
#include "KVSWriteFld.h"
#include <kvs/Message>
#include <kvs/VolumeObjectBase>
#include <kvs/StructuredVolumeExporter>
#include <kvs/UnstructuredVolumeExporter>

/// constructor
KVSWriteFld::KVSWriteFld()
{
  //m_object = new kvs::VolumeObjectBase();
  m_object = NULL;
}	
/// destructor
KVSWriteFld::~KVSWriteFld()
{
  //  delete m_object;	
}

bool KVSWriteFld::SetVolumeObject( void* volume )
{
  if( volume )
    {
      m_object = static_cast<kvs::VolumeObjectBase*>( volume );
      m_object->print(std::cout);
      if(!m_object){
	kvsMessageError( "Input object is not volume object." );
	return false;
      }		
      return true;
    }
  return false;
}


bool KVSWriteFld::SetOutputFilePath(std::string& file )
{
  if ( file == m_file ) return true;
  else if ( file.empty() )
    {
      m_file = "";
      m_object = NULL;
      return false;   
    }
  else
    {
      if(m_object)
	{
	  const kvs::VolumeObjectBase* volume = kvs::VolumeObjectBase::DownCast( m_object );
	  if ( !volume )
	    {
	      kvsMessageError("Input object is not volume dat.");
	      return false;
	    }	  
	  const kvs::VolumeObjectBase::VolumeType volume_type = volume->volumeType();
	  if(volume_type == kvs::VolumeObjectBase::Structured){
	    kvs::AVSField* fld = new kvs::StructuredVolumeExporter<kvs::AVSField>( kvs::StructuredVolumeObject::DownCast(m_object) );
	    fld->write(file);
	    return true;
	  }  		
	  else if(volume_type == kvs::VolumeObjectBase::Unstructured){
	    kvs::AVSUcd* fld = new kvs::UnstructuredVolumeExporter<kvs::AVSUcd>( kvs::UnstructuredVolumeObject::DownCast(m_object) );
	    fld->write(file);
	    return true;
	  }
	  else
	    return false;
	}
    }
  return false;
}

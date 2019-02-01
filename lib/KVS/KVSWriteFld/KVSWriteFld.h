/**
 * @file KVSWriteFld3D.h
 */
#ifndef _KVSWRITEFLD_H_
#define _KVSWRITEFLD_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>
namespace kvs {
  class VolumeObjectBase;
}

class KVSWriteFld : public RefCount
{
public:
  KVSWriteFld();
  ~KVSWriteFld();

  bool SetVolumeObject( void* object );
  bool SetOutputFilePath( std::string& file );
private:
  kvs::VolumeObjectBase* m_object;
  std::string m_file;
};

#endif //_KVSWRITEFLD_H_

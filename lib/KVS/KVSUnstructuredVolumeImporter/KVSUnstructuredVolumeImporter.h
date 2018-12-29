/**
 * @file KVSUnstructuredVolumeImporter.h
 */
#ifndef _KVSUNSTRUCTUREDVOLUMEIMPORTER_H_
#define _KVSUNSTRUCTUREDVOLUMEIMPORTER_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class UnstructuredVolumeObject;
}

class KVSUnstructuredVolumeImporter : public RefCount
{
public:
    KVSUnstructuredVolumeImporter();
    ~KVSUnstructuredVolumeImporter();
    const char* Object() const;
    bool SetFile( std::string& file );
    float MinValue();
    float MaxValue();

private:
    kvs::UnstructuredVolumeObject* m_object;
    std::string m_file;
    float m_min, m_max;
};

#endif //_KVSUNSTRUCTUREDVOLUMEIMPORTER_H_

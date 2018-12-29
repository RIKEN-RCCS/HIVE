/**
 * @file KVSStructuredVolumeImporter.h
 */
#ifndef _KVSSTRUCTUREDVOLUMEIMPORTER_H_
#define _KVSSTRUCTUREDVOLUMEIMPORTER_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class StructuredVolumeObject;
}

class KVSStructuredVolumeImporter : public RefCount
{
public:
    KVSStructuredVolumeImporter();
    ~KVSStructuredVolumeImporter();
    const char* Object() const;
    bool SetFile( std::string& file );

private:
    kvs::StructuredVolumeObject* m_object;
    std::string m_file;
};

#endif //_KVSSTRUCTUREDVOLUMEIMPORTER_H_

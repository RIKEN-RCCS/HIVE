/**
 * @file KVSDataImporter.h
 */
#ifndef _KVSDATAIMPORTER_H_
#define _KVSDATAIMPORTER_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class ObjectBase;
}

class KVSDataImporter : public RefCount
{
public:
    KVSDataImporter();
    ~KVSDataImporter();
    const char* Object() const;
    bool SetFile( std::string& file );

private:
    kvs::ObjectBase* m_object;
    std::string m_file;
};

#endif //_KVSDATAIMPORTER_H_

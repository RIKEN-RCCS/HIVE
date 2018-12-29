/**
 * @file KVSPolygonImporter.h
 */
#ifndef _KVSPOLYGONIMPORTER_H_
#define _KVSPOLYGONIMPORTER_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class PolygonObject;
}

class KVSPolygonImporter : public RefCount
{
public:
    KVSPolygonImporter();
    ~KVSPolygonImporter();
    const char* Object() const;
    bool SetFile( std::string& file );

private:
    kvs::PolygonObject* m_object;
    std::string m_file;
};

#endif //_KVSPOLYGONIMPORTER_H_

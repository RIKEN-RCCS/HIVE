/**
 * @file KVSTornadoVolumeData.h
 */
#ifndef _KVSTORNADOVOLUMEDATA_H_
#define _KVSTORNADOVOLUMEDATA_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class TornadoVolumeData;
}

class KVSTornadoVolumeData : public RefCount
{
public:
    KVSTornadoVolumeData();
    ~KVSTornadoVolumeData();
    const char* Object() const;
    bool SetResolution( int rx, int ry, int rz );
    bool SetTime( int time );

private:
    kvs::TornadoVolumeData* m_object;
};

#endif //_KVSTORNADOVOLUMEDATA_H_

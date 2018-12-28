/**
 * @file KVSHydrogenVolumeData.h
 */
#ifndef _KVSHYDROGENVOLUMEDATA_H_
#define _KVSHYDROGENVOLUMEDATA_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class HydrogenVolumeData;
}

class KVSHydrogenVolumeData : public RefCount
{
public:
    KVSHydrogenVolumeData();
    ~KVSHydrogenVolumeData();
    const char* Object() const;
    bool SetResolution( int rx, int ry, int rz );

private:
    kvs::HydrogenVolumeData* m_object;
};

#endif //_KVSHYDROGENVOLUMEDATA_H_

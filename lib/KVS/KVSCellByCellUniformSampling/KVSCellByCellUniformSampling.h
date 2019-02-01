/**
 * @file KVSCellByCellUniformSampling.h
 */
#ifndef _KVSCELLBYCELLUNIFORMSAMPLING
#define _KVSCELLBYCELLUNIFORMSAMPLING

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class VolumeObjectBase;
    class CellByCellUniformSampling;
    class TransferFunction;
}

class KVSCellByCellUniformSampling : public RefCount
{
public:
    KVSCellByCellUniformSampling();
    ~KVSCellByCellUniformSampling();

    const char* Object() const;
    bool Execute();
    bool SetVolumeObject( void * volume );
    bool SetRepetitionLevel( int level );
    bool SetSamplingStep( float step );
    bool SetMinMaxValues( float min, float max);
    bool SetTransferFunction( void* );

private:
    kvs::CellByCellUniformSampling* m_object;
    kvs::VolumeObjectBase* m_volume;
    float m_min, m_max;
    bool m_isChanged;
};

#endif //_KVSCELLBYCELLUNIFORMSAMPLING_H_

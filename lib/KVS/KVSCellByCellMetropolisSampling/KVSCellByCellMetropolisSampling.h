/**
 * @file KVSCellByCellMetropolisSampling.h
 */
#ifndef _KVSCELLBYCELLMETROPOLISSAMPLING_H_
#define _KVSCELLBYCELLMETROPOLISSAMPLING_H_

#include "Ref.h"
#include "Buffer.h"
#include <string>

namespace kvs {
    class VolumeObjectBase;
    class CellByCellMetropolisSampling;
    class TransferFunction;
}

class KVSCellByCellMetropolisSampling : public RefCount
{
 public:
    KVSCellByCellMetropolisSampling();
    ~KVSCellByCellMetropolisSampling();

    const char* Object() const;
    bool Execute();
    bool SetVolumeObject( void * volume );
    bool SetRepetitionLevel( int level );
    bool SetSamplingStep( float step );
    bool SetMinMaxValues( float min, float max);
    bool SetTransferFunction( void* );

 private:
    kvs::CellByCellMetropolisSampling* m_object;
    kvs::VolumeObjectBase* m_volume;
    float m_min, m_max;
    bool m_isChanged;
};

#endif //_KVSCELLBYCELLMETROPOLISSAMPLING_H_

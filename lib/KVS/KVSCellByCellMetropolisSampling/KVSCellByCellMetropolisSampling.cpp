/**
 * @file KVSCellByCellMetropolisSampling.cpp
 */
#include "KVSCellByCellMetropolisSampling.h"
#include <kvs/Message>
#include <kvs/CellByCellMetropolisSampling>
#include <kvs/VolumeObjectBase>
#include <iostream>

/// constructor
KVSCellByCellMetropolisSampling::KVSCellByCellMetropolisSampling()
{
    const size_t repetitions = 1;
    float step = 0.5f;
    m_isChanged = false;
    m_object = new kvs::CellByCellMetropolisSampling();
    m_object->setTransferFunction(  kvs::TransferFunction( 256 ) );
    m_object->setObjectDepth( 0.0f );
    m_object->setRepetitionLevel( repetitions );
    m_object->setSamplingStep( step );
}

/// destructor
KVSCellByCellMetropolisSampling::~KVSCellByCellMetropolisSampling()
{
    m_isChanged = false;
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSCellByCellMetropolisSampling::Object() const
{
    return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
}

/**
 * execute sampling
 * @return success(true) or failed(false)
 */ 
bool KVSCellByCellMetropolisSampling::Execute()
{
    if ( (m_volume == NULL) or !(m_isChanged) )
        return false;
    m_object->exec( m_volume );
    std::cout << "[DEBUG] CellByCellMetropolisSampling" << std::endl;
    size_t data_size = m_object->coords().byteSize()+m_object->colors().byteSize()+m_object->normals().byteSize();
    std::cout << "[DEBUG] Size of particle data : " << data_size << " [Byte]" << std::endl;
    m_isChanged = false;
    return true;
}

/**
 * set repetition level
 * @param level [in] repetition level
 * @return success(true) or failed(false)
 */ 
bool KVSCellByCellMetropolisSampling::SetRepetitionLevel( int level )
{
    if ( !m_object ) { return false; }
    m_object->setRepetitionLevel( level );
    m_isChanged = true;
    return true;
}

/**
 * set sampling step
 * @param step [in] sampling step
 * @return success(true) or failed(false)
 */ 
bool KVSCellByCellMetropolisSampling::SetSamplingStep( float step )
{
    if ( !m_object ) { return false; }
    m_object->setSamplingStep( step );
    m_isChanged = true;
    return true;
}

/**
 * set volume object
 * @param obj [in] volume object
 * @return success(true) or failed(false)
 */
bool KVSCellByCellMetropolisSampling::SetVolumeObject( void * volume )
{
    if ( !volume ) { return false; }
    m_volume = reinterpret_cast<kvs::VolumeObjectBase*>( volume );
    if ( (m_min == 0)&&(m_max == 0) ) {
	if ( !m_volume->hasMinMaxValues() ) m_volume->updateMinMaxValues();
	m_min = static_cast<float>( m_volume->minValue() );
	m_max = static_cast<float>( m_volume->maxValue() );
    }
    m_volume->setMinMaxValues( m_min, m_max );
    m_isChanged = true;
    return true;
}

/**
 * set min/max values
 * @param min [in] min value
 * @param max [in] max value
 * @return success(true) or failed(false)
 */
bool KVSCellByCellMetropolisSampling::SetMinMaxValues( float min, float max )
{
    m_min = min;
    m_max = max;
    m_isChanged = true;
    return true;
}

/**
 * set transfer function
 * @param object [in] transfer function pointer
 * @return success(true) or failed(false)
 */
bool KVSCellByCellMetropolisSampling::SetTransferFunction( void* tf )
{
    if ( !m_object ) { return false; }
    if ( !tf ) { return false; }
    m_object->setTransferFunction( *reinterpret_cast<kvs::TransferFunction*>( tf ) );
    m_isChanged = true;
    return true;
}

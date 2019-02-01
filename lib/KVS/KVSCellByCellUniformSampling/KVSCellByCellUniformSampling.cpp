/**
 * @file KVSCellByCellUniformSampling.cpp
 */
#include "KVSCellByCellUniformSampling.h"
#include <kvs/Message>
#include <kvs/CellByCellUniformSampling>
#include <kvs/VolumeObjectBase>
#include <iostream>

/// constructor
KVSCellByCellUniformSampling::KVSCellByCellUniformSampling()
{
    const size_t repetitions = 1;
    float step = 0.5f;
    m_isChanged = false;
    m_object = new kvs::CellByCellUniformSampling();
    m_object->setTransferFunction(  kvs::TransferFunction( 256 ) );
    m_object->setObjectDepth( 0.0f );
    m_object->setRepetitionLevel( repetitions );
    m_object->setSamplingStep( step );
}

/// destructor
KVSCellByCellUniformSampling::~KVSCellByCellUniformSampling()
{
    m_isChanged = false;
    delete m_object;
}

/**
 * get object
 * @return object pointer
 */ 
const char* KVSCellByCellUniformSampling::Object() const
{
    return reinterpret_cast<const char*>( static_cast<kvs::ObjectBase*>( m_object ) );
}

/**
 * execute sampling
 * @return success(true) or failed(false)
 */ 
bool KVSCellByCellUniformSampling::Execute()
{
    if ( (m_volume == NULL) or !(m_isChanged) )
        return false;
    m_object->exec( m_volume );
    std::cout << "[DEBUG] CellByCellUniformSampling" << std::endl;
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
bool KVSCellByCellUniformSampling::SetRepetitionLevel( int level )
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
bool KVSCellByCellUniformSampling::SetSamplingStep( float step )
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
bool KVSCellByCellUniformSampling::SetVolumeObject( void * volume )
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
bool KVSCellByCellUniformSampling::SetMinMaxValues( float min, float max )
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
bool KVSCellByCellUniformSampling::SetTransferFunction( void* tf )
{
    if ( !m_object ) { return false; }
    if ( !tf ) { return false; }
    m_object->setTransferFunction( *reinterpret_cast<kvs::TransferFunction*>( tf ) );
    m_isChanged = true;
    return true;
}

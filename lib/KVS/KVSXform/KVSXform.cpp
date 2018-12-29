/**
 * @file KVSXform.cpp
 */
#include "KVSXform.h"
#include <kvs/Matrix33>
#include <kvs/Vector3>
#include <kvs/Xform>

/// constructor
KVSXform::KVSXform()
{
    m_rotation = kvs::Mat3::Identity();
    m_scaling = kvs::Vec3::All( 1 );
    m_translation = kvs::Vec3::Zero();
    m_xform = new kvs::Xform( m_translation, m_scaling, m_rotation );
}

/// destructor
KVSXform::~KVSXform()
{
}

/**
 * set rotation
 * @param rx [in] rotation angle around x axis
 * @param ry [in] rotation angle around y axis
 * @param rz [in] rotation angle around z axis
 * @return success(true) or failed(false)
 */
bool KVSXform::SetRotation( float rx, float ry, float rz ) {
    m_rotation = kvs::Mat3::RotationY( ry ) * kvs::Mat3::RotationX( rx ) * kvs::Mat3::RotationZ( rz );
    return true;
}

/**
 * set scaling
 * @param sx [in] scaling rate toward x axis direction
 * @param sy [in] scaling rate toward y axis direction
 * @param sz [in] scaling rate toward z axis direction
 * @return success(true) or failed(false)
 */
bool KVSXform::SetScaling( float sx, float sy, float sz ) {
    m_scaling = kvs::Vec3( sx, sy, sz );
    return true;
}

/**
 * set translation
 * @param tx [in] translation value toward x axis direction
 * @param ty [in] translation value toward y axis direction
 * @param tz [in] translation value toward z axis direction
 * @return success(true) or failed(false)
 */
bool KVSXform::SetTranslation( float tx, float ty, float tz ) {
    m_translation = kvs::Vec3( tx, ty, tz );
    return true;
}

/**
 * get xform
 * @return xform pointer
 */ 
const char* KVSXform::Xform() const
{
    if ( m_xform )
    {
        m_xform = new kvs::Xform( m_translation, m_scaling, m_rotation );
        return reinterpret_cast<const char*>( m_xform );
    }
    return NULL;
}

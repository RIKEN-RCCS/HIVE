/**
 * @file KVSGenericObject.cpp
 */
#ifndef _KVSGENERICOBJECT_H_
#define _KVSGENERICOBJECT_H_

#include "Ref.h"
#include "Buffer.h"
#include "BufferImageData.h"

namespace kvs {
    class ObjectBase;
    class RendererBase;
}

class KVSGenericObject : public RefCount
{
public:
    enum DataType
    {
        GeometryPoint = 0,
        GeometryLine,
        GeometryPolygon,
        StructuredVolume,
        UnstructuredVolume,
        UnknownDataType
    };
   
private:
    DataType m_dataType;
    kvs::ObjectBase* m_object;
    kvs::RendererBase* m_renderer;
    float m_translate[3];
    float m_rot[3];
    float m_scale[3];
    float m_color[4];
    bool m_show_flag;
    bool m_shading_flag;
    bool m_gpu_flag;

public:
    KVSGenericObject();
    ~KVSGenericObject();
    const char* Object() const;
    const char* Renderer() const;
    bool SetObject( void * );
    bool SetTranslate( float tx, float ty, float tz );
    bool SetRotate( float rx, float ry, float rz );
    bool SetScale( float sx, float sy, float sz );
    bool SetColor( float red, float green, float blue, float opacity );
    bool Release();
    bool SetShowFlag( bool show );
    bool SetShadingFlag( bool shading );
    bool SetGPUFlag( bool gpu );

private:
    bool SelectRenderer();
    bool CheckDataType();
};

#endif //_KVSGENERICOBJECT_H_

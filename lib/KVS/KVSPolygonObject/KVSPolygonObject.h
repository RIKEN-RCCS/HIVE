
/**
 * @file KVSPolygonObject.cpp
 */
#ifndef _KVSPOLYGONOBJECT_H_
#define _KVSPOLYGONOBJECT_H_

#include "Ref.h"
#include "Buffer.h"
#include "BufferImageData.h"

namespace kvs {
    class PolygonObject;
    class RendererBase;
}

class KVSPolygonObject : public RefCount
{
public:
    KVSPolygonObject();
    ~KVSPolygonObject();
    bool SetTranslate( float tx, float ty, float tz );
    bool SetRotate( float rx, float ry, float rz );
    bool SetScale( float sx, float sy, float sz );
    bool SetColor( float r, float g, float b, float a );
    const char* PolygonObject() const;
    const char* Renderer() const;
    bool SetPolygonObject( void * );
    bool SetRenderer( void * );
    bool Release();
    bool SetShowFlag( bool show_flag );

private:
    kvs::PolygonObject* m_object;
    kvs::RendererBase* m_renderer;
    float m_translate[3];
    float m_rot[3];
    float m_scale[3];
    float m_color[4];
    bool m_show_flag;
};

#endif //_KVSPOLYGONOBJECT_H_


/**
 * @file KVSObject.cpp
 */
#ifndef _KVSOBJECT_H_
#define _KVSOBJECT_H_

#include "Ref.h"
#include "Buffer.h"
#include "BufferImageData.h"

namespace kvs {
    class ObjectBase;
    class RendererBase;
}

class KVSObject : public RefCount
{
public:
    KVSObject();
    ~KVSObject();
    bool SetTranslate( float tx, float ty, float tz );
    bool SetRotate( float rx, float ry, float rz );
    bool SetScale( float sx, float sy, float sz );
    const char* Object() const;
    const char* Renderer() const;
    bool SetObject( void * );
    bool SetRenderer( void * );
    bool Release();
    bool SetShowFlag( bool show_flag );
    
private:
    kvs::ObjectBase* m_object;
    kvs::RendererBase* m_renderer;
    float m_translate[3];
    float m_rot[3];
    float m_scale[3];
    bool m_show_flag;
};

#endif //_KVSOBJECT_H_

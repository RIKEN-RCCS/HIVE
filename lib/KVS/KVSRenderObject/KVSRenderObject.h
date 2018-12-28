/**
 * @file KVSRenderObject.cpp
 */
#ifndef _KVSRENDEROBJECT_H_
#define _KVSRENDEROBJECT_H_

#include "Ref.h"

namespace kvs {
    class GeometryObjectBase;
    class RendererBase;
    class Xform;
}

class KVSRenderObject : public RefCount
{
private:  
    kvs::GeometryObjectBase* m_object;
    kvs::RendererBase* m_renderer;
    void* m_renderer_input;
    bool m_shader_flag;
    bool m_shading_flag;
    bool m_show_flag;
    kvs::Xform* m_xform;

public:
    KVSRenderObject();
    ~KVSRenderObject();
    const char* Object() const;
    const char* Renderer() const;
    bool Release();
    bool SetObject( void* object );
    bool SetRenderer( void* renderer );
    bool SetShaderFlag( bool shader );
    bool SetShadingFlag( bool shading );
    bool SetShowFlag( bool show );
    bool SetXform( void* xform );

private:
    bool select_renderer();
};

#endif //_KVSRENDEROBJECT_H_

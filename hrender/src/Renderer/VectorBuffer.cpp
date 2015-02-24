#include <string>

#include "Analyzer.h"
#include "VectorBuffer.h"
#include "BufferVectorData.h"
#include "../RenderObject/VectorModel.h"
#include "Buffer.h"
#include "Commands.h"
#include "../Core/vxmath.h"

VectorBuffer::VectorBuffer(RENDER_MODE mode) : BaseBuffer(mode)
{
    m_line_vtx_id    = 0;
    m_tetra_vtx_id   = 0;
    Clear();
}

VectorBuffer::~VectorBuffer()
{
    Clear();
}

void VectorBuffer::Clear()
{
    if (m_line_vtx_id)  ReleaseBufferVBIB_SGL(m_line_vtx_id);
    if (m_tetra_vtx_id) ReleaseBufferVBIB_SGL(m_tetra_vtx_id);
    if (m_mat_id)       ReleaseBufferVBIB_SGL(m_mat_id);
    m_line_vtx_id    = 0;
    m_tetra_vtx_id   = 0;
    m_mat_id         = 0;
    m_lines_vnum     = 0;
    m_tetra_vnum     = 0;
}

bool VectorBuffer::Create(const VectorModel* model)
{
    bool r = true;
    if (!model) {
        fprintf(stderr,"Failed to create line: ");
        return false;
    }

    Clear();
    
    m_model = model;

    // load shader
    const std::string& shadername = model->GetShader();
    printf("%s\n", shadername.c_str());
    r &= loadShaderSrc(shadername.c_str());
    if (!r) {
        fprintf(stderr,"[Error]Not set shader\n");
        return false;
    }

    // make VectorData
    const BufferVectorData* vec = model->GetVector();
    if (!vec) {
        fprintf(stderr,"[Error]Invalid vector data\n");
        return false;
    }
    
    const int vecNum = vec->Position()->GetNum();
    if (vecNum <= 0) {
        fprintf(stderr,"[Error]Vector vertex empty\n");
        return false;
    }
    
    m_lines_vnum = vecNum * 2;
    m_tetra_vnum = vecNum * 4;

    // Create Line data
    RefPtr<Vec3Buffer> lineBuf = new Vec3Buffer();
    lineBuf->Create(m_lines_vnum);
    float* l3 = lineBuf->GetBuffer();
    const float* v3 = vec->Position()->GetBuffer();
    const float* d3 = vec->Direction()->GetBuffer();
    const float lengthScale = m_model->GetLengthScale();
    for (unsigned int i = 0; i < vecNum; ++i) {
        l3[2 * 3 * i    ] = v3[3 * i    ];
        l3[2 * 3 * i + 1] = v3[3 * i + 1];
        l3[2 * 3 * i + 2] = v3[3 * i + 2];
        l3[2 * 3 * i + 3] = v3[3 * i    ] + d3[3 * i    ] * lengthScale;
        l3[2 * 3 * i + 4] = v3[3 * i + 1] + d3[3 * i + 1] * lengthScale;
        l3[2 * 3 * i + 5] = v3[3 * i + 2] + d3[3 * i + 2] * lengthScale;
    }
    
    // Create Arrow data
    RefPtr<Vec3Buffer> tetraBuf = new Vec3Buffer();
    tetraBuf->Create(m_tetra_vnum);
    using namespace VX::Math;
    vec3* tv3 = reinterpret_cast<vec3*>(tetraBuf->GetBuffer());
    const float arrowSize = 1.0;//m_model->GetArrowSize();
    for (unsigned int i = 0; i < vecNum; ++i) {
        vec3 dir   (d3[3 * i], d3[3 * i + 1], d3[3 * i + 2]);
        vec3 center = vec3(v3[3 * i], v3[3 * i + 1], v3[3 * i + 2]) + dir * lengthScale;
        dir = normalize(dir);

        vec3 tnv = cross(dir, VX::Math::vec3(0,1,0));
        tv3[4 * i    ] = center + dir * arrowSize;
        tv3[4 * i + 1] = center + tnv * arrowSize;
        tv3[4 * i + 2] = center + (RotationAxis(dir, 120) * vec4(tnv, 0.0)).xyz() * arrowSize;
        tv3[4 * i + 3] = center + (RotationAxis(dir,-120) * vec4(tnv, 0.0)).xyz() * arrowSize;
    }

    // Create Line and tetra VB
    unsigned int normal_id, mat_id, tex_id, index_id;
    CreateVBIB_SGL(m_lines_vnum, lineBuf->GetBuffer(),  0, 0, 0, 0, 0, m_line_vtx_id,  normal_id, mat_id, tex_id, index_id);
    CreateVBIB_SGL(m_tetra_vnum, tetraBuf->GetBuffer(), 0, 0, 0, 0, 0, m_tetra_vtx_id, normal_id, mat_id, tex_id, index_id);

    return r;
}

void VectorBuffer::Render() const
{
    if (!m_model) {
        fprintf(stderr,"[Error] Not set vectormodel\n");
    }
    
    if (m_lines_vnum == 0 || m_tetra_vnum == 0) {
        fprintf(stderr,"[Error] Invalide vector data\n");
        return;
    }

    bindUniforms(m_model);
    
    const float w = m_model->GetLineWidth();
    LineWidth_SGL(w);
    
    BindLineVBIB_SGL(getProgram(), m_line_vtx_id, 0, 0, 0);
    DrawLineArrays_SGL(m_lines_vnum);
    
    BindTetraVBIB_SGL(getProgram(), m_tetra_vtx_id, 0, 0);
    DrawTetraArrays_SGL(m_tetra_vnum);
}


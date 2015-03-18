/**
 * @file BufferLineData.cpp
 * BufferLineData�N���X
 */
#include "BufferLineData.h"
#include "Buffer.h"
#include <vector>

class BufferLineData::Impl
{
private:
    RefPtr<Vec3Buffer>  m_pos;
    RefPtr<FloatBuffer> m_radius;
    RefPtr<FloatBuffer> m_mat;
    RefPtr<UintBuffer>  m_index;

public:
    /// �R���X�g���N�^
    Impl()
    {
        Clear();
    }
    
    /// �R���X�g���N�^
    Impl(BufferLineData* inst)
    {
        this->m_pos    = inst->Position();
        this->m_mat    = inst->Material();
        this->m_radius = inst->Radius();
        this->m_index  = inst->Index();
    }

    /// �f�X�g���N�^
    ~Impl()
    {
        m_pos    = 0;
        m_mat    = 0;
        m_radius = 0;
        m_index  = 0;
    }
    
    /// �����o�N���A
    void Clear()
    {
        m_pos    = new Vec3Buffer();
        m_mat    = new FloatBuffer();
        m_radius = new FloatBuffer();
        m_index  = new UintBuffer();
    }
    
    
    /**
     * BufferLineData�̍쐬
     * @param vertexnum �쐬���_��
     * @param indexnum  �쐬index��
     * @param useRadius ���a�w��
     */
    void Create(int vertexnum, int indexnum, bool useRadius)
    {
       m_pos->Create(vertexnum);
        m_mat->Create(vertexnum);
        if (useRadius)
            m_radius->Create(vertexnum);
        if (indexnum)
            m_index->Create(indexnum);
    }

    /**
     * ���_�o�b�t�@�擾
     * @return Vec3Buffer���_�o�b�t�@�ւ̎Q��
     */
    Vec3Buffer* Position() {
        return m_pos;
    }

    /**
     * �}�e���A��ID�o�b�t�@�擾
     * @return FloatBuffer�}�e���A��ID�o�b�t�@�ւ̎Q��
     */
    FloatBuffer* Material() {
        return m_mat;
    }

    /**
     * ���a�o�b�t�@�擾
     * @return FloatBuffer���a�o�b�t�@�ւ̎Q��
     */
    FloatBuffer* Radius() {
        return m_radius;
    }

    /**
     * Index�o�b�t�@�擾
     * @return Index�o�b�t�@�ւ̎Q��
     */
    UintBuffer* Index() {
        return m_index;
    }
    
    /**
     * ���_�o�b�t�@�擾
     * @return Vec3Buffer���_�o�b�t�@�ւ̎Q��
     */
    Vec3Buffer* Position() const {
        return m_pos;
    }
    
    /**
     * �}�e���A��ID�o�b�t�@�擾
     * @return FloatBuffer�}�e���A��ID�o�b�t�@�ւ̎Q��
     */
    FloatBuffer* Material() const {
        return m_mat;
    }
    
    /**
     * ���a�o�b�t�@�擾
     * @return FloatBuffer���a�o�b�t�@�ւ̎Q��
     */
    FloatBuffer* Radius() const {
        return m_radius;
    }
    
    /**
     * Index�o�b�t�@�擾
     * @return Index�o�b�t�@�ւ̎Q��
     */
    UintBuffer* Index() const {
        return m_index;
    }
};

/// constructor
BufferLineData::BufferLineData()
{
    m_imp = new BufferLineData::Impl();
}

/// destructor
BufferLineData::~BufferLineData()
{
    delete m_imp;
}

BufferLineData::BufferLineData(BufferLineData* inst)
{
    m_imp = new BufferLineData::Impl(inst);
}

void BufferLineData::Clear()
{
    m_imp->Clear();
}

void BufferLineData::Create(int vertexnum, int indexnum, bool useRadius)
{
    m_imp->Create(vertexnum, indexnum, useRadius);
}

Vec3Buffer* BufferLineData::Position() {
    return m_imp->Position();
}

FloatBuffer* BufferLineData::Material() {
    return m_imp->Material();
}

FloatBuffer* BufferLineData::Radius() {
    return m_imp->Radius();
}

UintBuffer* BufferLineData::Index() {
    return m_imp->Index();
}

Vec3Buffer* BufferLineData::Position() const {
    return m_imp->Position();
}

FloatBuffer* BufferLineData::Material() const {
    return m_imp->Material();
}

FloatBuffer* BufferLineData::Radius() const {
    return m_imp->Radius();
}

UintBuffer* BufferLineData::Index() const {
    return m_imp->Index();
}



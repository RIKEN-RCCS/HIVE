/**
 * @file BufferTetraData.cpp
 * BufferTetraData�N���X
 */
#include "BufferTetraData.h"
#include "Buffer.h"
#include <vector>

class BufferTetraData::Impl
{
private:
    RefPtr<Vec3Buffer >  m_pos;
    RefPtr<UintBuffer >  m_index;
public:
    /// �R���X�g���N�^
    Impl()
    {
        Clear();
    }
    
    /// �R���X�g���N�^
    Impl(BufferTetraData* inst)
    {
        this->m_pos      = inst->Position();
        this->m_index    = inst->Index();
    }
    
    /// �f�X�g���N�^
    ~Impl()
    {
        m_pos      = 0;
        m_index    = 0;
    }

    /**
     * BufferTetraData�̍쐬
     * @param vertexnum �쐬���_��
     * @param indexnum  �쐬index��
     */
    void Create(int vertexnum, int indexnum)
    {
        m_pos->Create(vertexnum);
        m_index->Create(indexnum);
    }
    
    /// �����o�N���A
    void Clear()
    {
        m_pos      = new Vec3Buffer();
        m_index    = new UintBuffer();
    }
    
    /// �f�o�b�O�p
    void print()
    {
        /*	printf("Position() %08p\n", m_pos.Get()      );
         printf("Index()    %08X\n", m_index.Get()    );*/
    }
    
    /**
     * ���_�o�b�t�@�擾
     * @return Vec3Buffer���_�o�b�t�@�ւ̎Q��
     */
    Vec3Buffer  *Position() { return m_pos;      }

    /**
     * Index�o�b�t�@�擾
     * @return Index�o�b�t�@�ւ̎Q��
     */
    UintBuffer  *Index()    { return m_index;    }
};

/// constructor
BufferTetraData::BufferTetraData()
{
    m_imp = new BufferTetraData::Impl();
}

/// constructor
BufferTetraData::BufferTetraData(BufferTetraData* inst)
{
    m_imp = new BufferTetraData::Impl(inst);
}

/// destructor
BufferTetraData::~BufferTetraData()
{
    delete m_imp;
}

void BufferTetraData::Create(int vertexnum, int indexnum)
{
    m_imp->Create(vertexnum, indexnum);
}

void BufferTetraData::Clear()
{
    m_imp->Clear();
}

void BufferTetraData::print()
{
    m_imp->print();
}

Vec3Buffer  *BufferTetraData::Position() { return m_imp->Position(); }
UintBuffer  *BufferTetraData::Index()    { return m_imp->Index();    }


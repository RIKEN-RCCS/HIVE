/**
 * @file SphLoader.cpp
 * SPH�f�[�^���[�_�[
 */
#include <stdio.h>
#include <string.h>
#include "SphLoader.h"
#include "SimpleSPH.h"
#include "BufferVolumeData.h"

/// �R���X�g���N�^
SPHLoader::SPHLoader()
{
    Clear();
}

/// �f�X�g���N�^
SPHLoader::~SPHLoader()
{
    Clear();
}

/// �����o�N���A
void SPHLoader::Clear()
{
    m_volume = 0;
}

/**
 * SPH�f�[�^�̃��[�h
 * @param filename �t�@�C���p�X
 * @retval true ����
 * @retval false ���s
 */
bool SPHLoader::Load(const char* filename)
{
    Clear();
    m_volume = new BufferVolumeData();

    SimpleSPH sph;
    const float* buf = sph.Load(filename);
    if (!buf) {
        fprintf(stderr,"Failed to load SPH volume: %s\n", filename);
        return false;
    }
    const int w = sph.GetDim(0);
    const int h = sph.GetDim(1);
    const int d = sph.GetDim(2);
    const int c = sph.GetComponent();
    m_volume->Create(w, h, d, c);
    FloatBuffer* buffer = m_volume->Buffer();
    const int fnum = w * h * d * c;
    memcpy(buffer->GetBuffer(), buf, fnum * sizeof(float));
    delete [] buf;

    return true;
}

/**
 * SPHWidth�擾
 * @retval Width
 */
int SPHLoader::Width()    {
    return m_volume->Width();
}

/**
 * SPHHeight�擾
 * @retval Height
 */
int SPHLoader::Height()   {
    return m_volume->Height();
}

/**
 * SPHDepth�擾
 * @retval Depth
 */
int SPHLoader::Depth()    {
    return m_volume->Depth();
}

/**
 * SPHComponent�擾
 * @retval Component��
 */
int SPHLoader::Component() {
    return m_volume->Component();
}

/**
 * SPH�f�[�^�o�b�t�@�Q�Ǝ擾
 * @retval FloatBuffer�A�h���X
 */
FloatBuffer* SPHLoader::Buffer() {
    return m_volume->Buffer();
}

/**
 * VolumeData�Q�Ǝ擾
 * @retval VolumeData�Q��
 */
BufferVolumeData *SPHLoader::VolumeData()
{
    return m_volume;
}

/**
 * @file HdmLoader.cpp
 * HDM�f�[�^���[�_�[
 */


#ifndef HIVE_WITH_HDMLIB
#error "HIVE_WITH_HDMLIB must be defined when you compile HDMLoader module"
#endif

#include <mpi.h> // must include mpi.h befor stdio.h for Intel MPI compiler.

#include <stdio.h>
#include <string.h>

#include <string>

#include "HdmLoader.h"
#include "SimpleVOL.h"


#include "BlockFactory.h"
#include "Block.h"
#include "BlockManager.h"
#include "Scalar3D.h"

//#include "LeafBlockLoader.h"
#include "BCMFileLoader.h"
#include "BCMFileSaver.h"

// @todo { implement }

/// �R���X�g���N�^
HDMLoader::HDMLoader()
{
    Clear();
}

/// �f�X�g���N�^
HDMLoader::~HDMLoader()
{
    Clear();
}

/// �{�����[���N���A
void HDMLoader::Clear()
{
    m_volume.Clear();
}

/**
 * HDM�f�[�^�̃��[�h
 * @param filename �t�@�C���p�X
 * @retval true ����
 * @retval false ���s
 */
bool HDMLoader::Load(const char* cellidFilename, const char* dataFilename)
{
    Clear();

	// cellid.bcm
	BCMFileIO::BCMFileLoader loader(cellidFilename, /* bscatrer */NULL);

	BlockManager& blockManager = BlockManager::getInstance();
    blockManager.printBlockLayoutInfo();

	// data.bcm
	if( !loader.LoadAdditionalIndex(dataFilename) ){
		printf("err : Load File Error %s)\n", dataFilename);
	    return false;
	}



    return false;
}

/**
 * HDMWidth�擾
 * @retval Width
 */
int HDMLoader::Width()    {
    return m_volume.Width();
}

/**
 * HDMHeight�擾
 * @retval Height
 */
int HDMLoader::Height()   {
    return m_volume.Height();
}

/**
 * HDMDepth�擾
 * @retval Depth
 */
int HDMLoader::Depth()    {
    return m_volume.Depth();
}

/**
 * HDMComponent�擾
 * @retval Component��
 */
int HDMLoader::Component() {
    return m_volume.Component();
}

/**
 * HDM�f�[�^�o�b�t�@�Q�Ǝ擾
 * @retval FloatBuffer�A�h���X
 */
FloatBuffer* HDMLoader::Buffer() {
    return m_volume.Buffer();
}

/**
 * VolumeData�Q�Ǝ擾
 * @retval VolumeData�Q��
 */
BufferVolumeData *HDMLoader::VolumeData()
{
    return &m_volume;
}


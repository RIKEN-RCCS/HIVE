#include "PdbLoader.h"
#include "tiny_pdb.h"
#include "Buffer.h"
#include <cstring>

PDBLoader::PDBLoader(){}
PDBLoader::~PDBLoader(){};

void PDBLoader::Clear()
{
	ball.Clear();
	stick.Clear();
}

bool PDBLoader::Load(const char* filename){
	Clear();

    tinypdb::TinyPDB pdb(filename);
    if (pdb.Parse(/* isBondGenerated = */ true)) {
        fprintf(stderr,"[PDBLoader] PDB parsing failed: %s \n", filename);
        return false;
    }

    const size_t numAtoms = pdb.GetAtoms().size();

    {
        ball.Create(numAtoms);
        Vec3Buffer*  pos     = ball.Position();
        FloatBuffer* mat     = ball.Material();
        FloatBuffer* radius  = ball.Radius();

        printf("[PDBLoader] # of atoms: %ld\n", numAtoms);

        float* pp = pos->GetBuffer();
        for (size_t i = 0; i < numAtoms; i++) {
            pp[3*i+0] = pdb.GetAtoms()[i].GetX();
            pp[3*i+1] = pdb.GetAtoms()[i].GetY();
            pp[3*i+2] = pdb.GetAtoms()[i].GetZ();
        }

        // @fixme
        float* rad = radius->GetBuffer();
        for (int i = 0; i < numAtoms; ++i) {
            rad[i] = 0.25f;
        }

        // @todo
        memset(mat->GetBuffer(), 0, sizeof(float) * mat->GetNum());
    }


    {

        // We reprent Bond as line primitives.
        // @todo { remove duplicated bonds. }
        std::vector<float> bondLines;
        for (unsigned int i = 0; i < numAtoms; i++) {

          tinypdb::Atom& atom = pdb.GetAtoms()[i];

          for (unsigned int j = 0; j < atom.GetBonds().size(); j++) {
            const tinypdb::Atom* dst = atom.GetBonds()[j];

            bondLines.push_back(atom.GetX());
            bondLines.push_back(atom.GetY());
            bondLines.push_back(atom.GetZ());

            bondLines.push_back(dst->GetX());
            bondLines.push_back(dst->GetY());
            bondLines.push_back(dst->GetZ());

          }

        }

        size_t numBonds = bondLines.size() / 3 / 2;
        size_t numBondVertices = numBonds * 2;

        printf("[PDBLoader] # of bonds: %ld\n", numBonds);

        stick.Create(numBondVertices, /* index num = */0, /* use radius */true);
        Vec3Buffer*  pos     = stick.Position();
        FloatBuffer* mat     = stick.Material();
        FloatBuffer* radius  = stick.Radius();
        //UintBuffer*  index   = stick.Index();  // not used.

        float* pp = pos->GetBuffer();
        for (size_t i = 0; i < numBondVertices; i++) {
            pp[3*i+0] = bondLines[3*i+0];
            pp[3*i+1] = bondLines[3*i+1];
            pp[3*i+2] = bondLines[3*i+2];
        }

        // @todo
        float* rad = radius->GetBuffer();
        for (int i = 0; i < numBondVertices; ++i) {
            rad[i] = 1.0f;
        }

        // @todo
        memset(mat->GetBuffer(), 0, sizeof(float) * mat->GetNum());
    }

	return true;
}

BufferPointData *PDBLoader::BallData()
{
	return &ball;
}

BufferLineData *PDBLoader::StickData()
{
	return &stick;
}

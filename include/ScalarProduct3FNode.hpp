/*
  ScalarProduct3FNode.hpp
  =======================
  Header for ScalarProduct3FNode class
*/
#ifndef SM4M_SCALARPRODUCT3FNODE
#define SM4M_SCALARPRODUCT3FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

/*
  The ScalarProduct3FNode computes a scalar multiplication on the given input vector of dimension 3.
*/
class ScalarProduct3FNode : public MPxNode
{

	public:

		static MTypeId id;
		static MObject scalar;
		static MObject vector;
		static MObject output;

		MStatus compute(const MPlug& plug, MDataBlock& data);
		static MStatus init();
		static void* creator();

};

#endif
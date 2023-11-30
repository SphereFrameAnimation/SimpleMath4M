/*
  ScalarProduct2FNode.hpp
  =======================
  Header for ScalarProduct2FNode class
*/
#ifndef SM4M_SCALARPRODUCT2FNODE
#define SM4M_SCALARPRODUCT2FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

/*
  The ScalarProduct2FNode computes a scalar multiplication on the given input vector of dimension 2.
*/
class ScalarProduct2FNode : public MPxNode
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
/*
  Arith3FNode.hpp
  ===============
  Header for Arith3FNode class.
*/
#ifndef SM4M_ARITH3FNODE
#define SM4M_ARITH3FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
#include "maya/MFnEnumAttribute.h"
/*
  The Arith3FNode computes a specified arithmetic operation on two three-dimensional float input vectors.
  Arithmetic operations include: addition and subtraction.
*/
class Arith3FNode : public MPxNode
{

public:

	static MTypeId id;
	static MObject input0;
	static MObject input1;
	static MObject output0;
	static MObject mode;

	MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
	static void* creator();
	static MStatus init();

};

#endif
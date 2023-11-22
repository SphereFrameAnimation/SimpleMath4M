/*
  Cross3FNode.hpp
  ===============
  Header for Cross3FNode class.
*/
#ifndef SM4M_CROSS3FNODE
#define SM4M_CROSS3FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"
/*
  The Cross3FNode computes the cross product between input0 and input1. Cross product is ordered (input0)x(input1).
*/
class Cross3FNode : public MPxNode
{

public:

	static MTypeId id;
	static MObject input0;
	static MObject input1;
	static MObject output0;

	MStatus compute(const MPlug& plug, MDataBlock& dataBlock);
	static void* creator();
	static MStatus init();

};

#endif
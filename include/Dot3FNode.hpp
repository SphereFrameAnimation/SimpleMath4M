/*
  Dot3FNode.hpp
  =============
  Header for Dot3FNode class
*/
#ifndef SM4M_DOT3FNODE
#define SM4M_DOT3FNODE

#include "maya/MPxNode.h"
#include "maya/MFnNumericAttribute.h"

/*
  The Dot3FNode computes the vector dot product of two three-dimensional float input vectors.
*/
class Dot3FNode : public MPxNode
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